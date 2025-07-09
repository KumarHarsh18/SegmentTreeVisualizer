#include <SFML/Graphics.hpp>
#include "../include/SegmentTree.hpp"
#include <vector>
#include <string>
#include <cmath>

void drawNode(sf::RenderWindow& window, int x, int y, const std::string& text) {
	sf::CircleShape circle(30);
	circle.setFillColor(sf::Color::White);
	circle.setOutlineColor(sf::Color::Black);
	circle.setOutlineThickness(2);
	circle.setPosition(x, y);

	window.draw(circle);

	sf::Font font;
	if (!font.loadFromFile("assets/font.ttf")) return;

	sf::Text label(text, font, 18);
	label.setFillColor(sf::Color::Black);
	label.setPosition(x + 10, y + 5);
	window.draw(label);
}

void drawTree(sf::RenderWindow& window, const std::vector<int>& tree, int node, int l, int r, int x, int y, int offsetX) {
	if (l > r || node >= (int)tree.size()) return;

	std::string val = std::to_string(tree[node]);
	drawNode(window, x, y, val);

	if (l == r) return;

	int mid = (l + r) / 2;
	int leftX = x - offsetX;
	int rightX = x + offsetX;
	int childY = y + 100;

	sf::Vertex line1[] = { sf::Vertex(sf::Vector2f(x+30, y+30)), sf::Vertex(sf::Vector2f(leftX+30, childY+30)) };
	sf::Vertex line2[] = { sf::Vertex(sf::Vector2f(x+30, y+30)), sf::Vertex(sf::Vector2f(rightX+30, childY+30)) };
	window.draw(line1, 2, sf::Lines);
	window.draw(line2, 2, sf::Lines);

	drawTree(window, tree, 2 * node, l, mid, leftX, childY, offsetX / 2);
	drawTree(window, tree, 2 * node + 1, mid + 1, r, rightX, childY, offsetX / 2);
}

int main() {
	std::vector<int> arr = { 1, 3, 5, 7, 9, 11 };
	SegmentTree st(arr);

	sf::RenderWindow window(sf::VideoMode(1000, 600), "Segment Tree Visualizer");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		drawTree(window, st.tree, 1, 0, arr.size() - 1, 500, 30, 200);
		window.display();
	}

	return 0;
}

