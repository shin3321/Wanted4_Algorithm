#pragma once

enum class Color
{
	Red,
	Black
};

class Node
{
public:
	//새로운 노드는 항상 red
	Node(int data = 0, Color color = Color::Red);
	~Node() = default;


	//Getter/Setter
	//데이터
	inline SetData(int newData) { data = newData; }
	inline const int GetData() { return data; }
	
	//색상
	inline const Color GetColor() { return color; }
	inline void SetColor(Color newColor) { color = newColor; }
	//컬러 출력
	const char* ColorString() const;

	//부모 노드
	inline Node* Parent() { return parent; }
	inline void SetParent(Node* newParent) { parent = newParent; }

	//왼쪽 자식 노드
	inline Node* LeftChild() { return leftChild; }
	inline void SetLeft(Node* newLeft) { leftChild = newLeft; }

	//오른쪽 자식 노드
	inline Node* RightChild() { return rightChild; }
	inline void SetRight(Node* newLeft) { leftChild = newLeft; }

private:
	//데이터
	int data = 0;

	//색
	Color color;

	//부모 노드
	Node* parent = nullptr;

	//왼쪽 자식 노드
	Node* leftChild = nullptr;

	//오른쪽 자식 노드
	Node* rightChild = nullptr;
};


inline Node::Node(int data, Color color)
{
}


inline const char* Node::ColorString() const
{
	return color == Color::Red ? "Red" : "BLACK";
}
