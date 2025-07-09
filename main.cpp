#include <SFML/Graphics.hpp>
#include "../include/SegmentTree.hpp"
#include <vector>
#include <string>

int main() {
    std::vector<int> data = {5, 3, 8, 6, 1, 4, 7, 2};
    SegmentTree st(data);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Segment Tree Visualizer");

    sf::Font font;
    font.loadFromFile("assets/font.ttf");

    const std::vector<int>& tree = st.getTree();
    std::vector<sf::Text> nodes;

    for (int i = 0; i < (int)tree.size(); ++i) {
        if (tree[i] == 0) continue;

        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(tree[i]));
        text.setCharacterSize(18);
        text.setFillColor(sf::Color::White);
        float x = 40 + (i * 20) % 700;
        float y = 100 + ((i * 20) / 700) * 60;
        text.setPosition(x, y);
        nodes.push_back(text);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();
        for (auto& node : nodes)
            window.draw(node);
        window.display();
    }

    return 0;
}
