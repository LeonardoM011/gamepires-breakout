#pragma once
#include <string>
#include <tinyxml2/tinyxml2.h>
#include "Assert.h"

struct Brick {
	char id;
	std::string texture;
	int hitPoints;
	std::string hitSound;
	std::string breakSound;
	int breakScore;
};

class XMLParser {
public:
	XMLParser(const std::string& filePath);
	~XMLParser();
	int getRowCount();
	int getColumnCount();
	int getRowSpacing();
	int getColumnSpacing();
	std::string getBackgroundTexture();
	std::vector<Brick> getBrickTypes();
	std::vector<std::vector<char>> getLayout();
private:
	tinyxml2::XMLDocument m_Doc;
	tinyxml2::XMLNode* m_Root;
};

