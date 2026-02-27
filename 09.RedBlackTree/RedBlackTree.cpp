#include "RedBlackTree.h"

Node* RedBlackTree::nil = nullptr;

Node* RedBlackTree::CreateNode(int data, Color color)
{
	Node* newNode = new Node(data, color);
	newNode->SetLeft(nil);
	newNode->SetRight(nil);

	return newNode;
}

RedBlackTree::RedBlackTree()
{
	//nil이 없으면 값: 0, 색상: black으로 초기화
	if (nil == nullptr)
	{
		nil = new Node(0, Color::Black);
	}

	root = nil;
}

RedBlackTree::~RedBlackTree()
{

}

bool RedBlackTree::Find(int data, Node** outData)
{
	//트리에 아무것도 없다면 실패
	if (root == nil)
		return false;

	//재귀적으로 검색
	FindRecursive(root, outData, data);
}

bool RedBlackTree::Insert(int data)
{
	//중복 데이터가 있는지 확인
	Node* newNode = nullptr;
	if (Find(data, &newNode))
	{
		std::cout
			<< "오류 - 노드 추가 실패: 이미 같은 값이 있습니다. 입력 값: "
			<< data << "\n";

		return false;
	}
	InsertRecursive(CreateNode(data, Color::Red));
	return false;
}

void RedBlackTree::Remove(int data)
{
}

void RedBlackTree::Print(int depth, int blackCount)
{
}

bool RedBlackTree::FindRecursive(Node* node, Node** outNode, int data)
{
	//검색 실패
	if (node == nil)
	{
		return false;
	}

	if (node->GetData() == data)
	{
		*outNode = node;
		return true;
	}

	//검색할 데이터가 현재 노드 값보다 작으면 왼쪽으로 진행
	if (node->GetData() > data)
	{
		FindRecursive(node->LeftChild(), outNode, data);
	}
	//크면 오른쪽으로 진행
	else
	{
		FindRecursive(node->RightChild(), outNode, data);
	}
}

void RedBlackTree::InsertRecursive(Node* newNode)
{
	//트리가 비어 있을 경우, 루트로 설정
	if (root == nil)
	{
		root = newNode;
		root->SetColor(Color::Black);
		return;
	}

	//트리가 비어 있지 않으면 재귀적으로 위치 검색 후 삽입
	InsertRecursive(root, newNode);

	//삽입된 노드 값 정리
	newNode->SetColor(Color::Red);
	newNode->SetLeft(nil);
	newNode->SetRight(nil);

	//삽입 후 재정렬 처리
	RestructireAfterInsert(newNode);
}

void RedBlackTree::InsertRecursive(Node* node, Node* newNode)
{

}

void RedBlackTree::RestructireAfterInsert(Node* newNode)
{
	//부모 노드가 빨간색인 경우
	while (newNode != root && newNode->Parent()->GetColor() == Color::Red)
	{
		//삼촌 구하기
		//지금 부모가 조부모의 왼쪽일 때
		if (newNode->Parent() == newNode->Parent()->Parent()->LeftChild())
		{
			Node* uncle = newNode->Parent()->RightChild();
		}
		//지금 부모가 조부모의 오르ㅜㄴ쪽일 때
		else
		{

		}
	}

	//부모가 조부모 기준 오른쪽 자손일때

}

void RedBlackTree::RestructireAfterRemove(Node* newNode)
{
}

void RedBlackTree::RotatorLeft(Node* node)
{
}

void RedBlackTree::RotatorRight(Node* node)
{
}

Node* RedBlackTree::FindMinRecursive(Node* node)
{
	return nullptr;
}

Node* RedBlackTree::FindMaxRecursive(Node* node)
{
	return nullptr;
}

void RedBlackTree::RemoveImpl(Node* node)
{
}
