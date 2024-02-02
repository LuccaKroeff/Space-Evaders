#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>

struct Vertex {
    float x, y, z;
};

struct BoundingBox {
    float minX, minY, minZ;
    float maxX, maxY, maxZ;
};

// Função para calcular a bounding box de um objeto a partir de um arquivo .obj
BoundingBox CalculateBoundingBox(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;
    std::vector<Vertex> vertices;

    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo .obj." << std::endl;
        // Retorna uma bounding box padrão ou trata o erro de outra maneira
        return BoundingBox{0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f};
    }

    // Loop para ler as coordenadas dos vértices do arquivo .obj
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "v") {
            Vertex vertex;
            iss >> vertex.x >> vertex.y >> vertex.z;
            vertices.push_back(vertex);
        }
    }

    // Inicializa os limites da bounding box com valores extremos
    float minX = std::numeric_limits<float>::max();
    float minY = std::numeric_limits<float>::max();
    float minZ = std::numeric_limits<float>::max();
    float maxX = std::numeric_limits<float>::lowest();
    float maxY = std::numeric_limits<float>::lowest();
    float maxZ = std::numeric_limits<float>::lowest();

    // Encontra os valores mínimos e máximos em cada dimensão
    for (const auto& vertex : vertices) {
        minX = std::min(minX, vertex.x);
        minY = std::min(minY, vertex.y);
        minZ = std::min(minZ, vertex.z);
        maxX = std::max(maxX, vertex.x);
        maxY = std::max(maxY, vertex.y);
        maxZ = std::max(maxZ, vertex.z);
    }

    return BoundingBox{minX, minY, minZ, maxX, maxY, maxZ};
}

int DefineBoundingBox() {
    // Substitua o caminho do arquivo pelo caminho real do seu arquivo .obj
    std::string filePath = "caminho/do/seu/arquivo.obj";

    BoundingBox boundingBox = CalculateBoundingBox(filePath);

    // Imprime os valores da bounding box
    std::cout << "BoundingBox:" << std::endl;
    std::cout << "MinX: " << boundingBox.minX << ", MaxX: " << boundingBox.maxX << std::endl;
    std::cout << "MinY: " << boundingBox.minY << ", MaxY: " << boundingBox.maxY << std::endl;
    std::cout << "MinZ: " << boundingBox.minZ << ", MaxZ: " << boundingBox.maxZ << std::endl;

    return 0;
}
