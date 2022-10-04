#include <iostream>
#include <queue>

// 한 직원은 최대 두 명의 부하를 거느림
struct node {
	std::string position;
	node* first;
	node* second;
};

// 프로그램 코드에서 이 노드를 직접 조작하지는 않을 것
struct org_tree {
	node* root;
};

// 루트 노드를 생성하는 함수
static org_tree create_org_structure(const std::string& pos) {
	org_tree tree;
	tree.root = new node{ pos, NULL, NULL };
	return tree;
}

// 특정 직책 이름에 해당하는 노드를 찾아서 반환하는 함수
static node* find(node* root, const std::string& value) {
	
	if (root == NULL) {		// root가 없는 경우
		return NULL;
	}
	if (root->position == value) {
		return root;
	}
	auto firstFound = org_tree::find(root->first, value);

	if (firstFound != NULL) {
		return firstFound;
	}

	return org_tree::find(root->second, value);
}

bool addSubordinate(const std::string& manager, const std::string& subordinate) {
	auto managerNode = org_tree::find(root, manager);

	if (!managerNode) {

	}
}



