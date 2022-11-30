#include "XMLParser.h"

XMLParser::XMLParser(const std::string &filePath) {
	tinyxml2::XMLError eResult = m_Doc.LoadFile(filePath.c_str());
	ASSERT_THAT(eResult == tinyxml2::XML_SUCCESS, "xml failed to load");

	m_Root = m_Doc.FirstChild();
	ASSERT_THAT(m_Root != nullptr, "xml failed to load root node");
}

XMLParser::~XMLParser() {}

int XMLParser::getRowCount() {
	int res;
	m_Root->ToElement()->FindAttribute("RowCount")->QueryIntValue(&res);
	return res;
}

int XMLParser::getColumnCount() {
	int res;
	m_Root->ToElement()->FindAttribute("ColumnCount")->QueryIntValue(&res);
	return res;
}

int XMLParser::getRowSpacing() {
	int res;
	m_Root->ToElement()->FindAttribute("RowSpacing")->QueryIntValue(&res);
	return res;
}

int XMLParser::getColumnSpacing() {
	int res;
	m_Root->ToElement()->FindAttribute("ColumnSpacing")->QueryIntValue(&res);
	return res;
}

std::string XMLParser::getBackgroundTexture() {
	const char* res;
	res = m_Root->ToElement()->FindAttribute("BackgroundTexture")->Value();
	return std::string(res);
}

std::vector<BrickXML> XMLParser::getBrickTypes() {
	tinyxml2::XMLElement* brickList = m_Root->FirstChildElement("BrickTypes")->FirstChildElement("BrickType");
	std::vector<BrickXML> res;
	while(brickList != nullptr) {
		BrickXML brick;

		const char* id;
		id = brickList->FindAttribute("Id")->Value();
		brick.id = id[0];

		const char *texture;
		texture = brickList->FindAttribute("Texture")->Value();
		brick.texture = std::string(texture);

		const char *hitPoints;
		hitPoints = brickList->FindAttribute("HitPoints")->Value();
		if(!std::strcmp(hitPoints, "Infinite")) {
			brick.hitPoints = -1;
		} else {
			brick.hitPoints = std::stoi(std::string(hitPoints));
		}

		const char *hitSound;
		hitSound = brickList->FindAttribute("HitSound")->Value();
		brick.hitSound = std::string(hitSound);

		if(brickList->FindAttribute("BreakSound") == nullptr) {
			brick.breakSound = "";
		} else {
			const char *breakSound;
			breakSound = brickList->FindAttribute("BreakSound")->Value();
			brick.breakSound = std::string(breakSound);
		}

		if(brickList->FindAttribute("BreakScore") == nullptr) {
			brick.breakScore = 0;
		} else {
			int breakScore;
			brickList->FindAttribute("BreakScore")->QueryIntValue(&breakScore);
			brick.breakScore = breakScore;
		}

		res.push_back(brick);
		brickList = brickList->NextSiblingElement("BrickType");
	}

	return res;
}

std::vector<std::vector<char>> XMLParser::getLayout() {
	int rows = getRowCount();
	int cols = getColumnCount();

	const char *cstr;
	cstr = m_Root->FirstChildElement("Bricks")->GetText();
	std::string stream = std::string(cstr);

	int stuckCounter = 0;
	std::vector<std::vector<char>> res;
	for(int i = 0; i < rows; i++) {
		std::vector<char> rowVec;
		for(int j = 0; j < cols;) {
			char cur = stream[0];
			if((cur >= 'a' and cur <= 'z') or (cur >= 'A' and cur <= 'Z') or cur == '_') {
				rowVec.push_back(cur);
				j++;
			}
			stream = stream.erase(0, 1);
			// If stuck just return empty vector
			if(stuckCounter > 1000)
				return std::vector<std::vector<char>>();
			stuckCounter++;
		}
		res.push_back(rowVec);
	}
	return res;
}
