#include <iostream>
#include <queue>

// �� ������ �ִ� �� ���� ���ϸ� �Ŵ���
struct node {
	std::string position;
	node* first;
	node* second;
};

// ���α׷� �ڵ忡�� �� ��带 ���� ���������� ���� ��
struct org_tree {
	node* root;
};

// ��Ʈ ��带 �����ϴ� �Լ�
static org_tree create_org_structure(const std::string& pos) {
	org_tree tree;
	tree.root = new node{ pos, NULL, NULL };
	return tree;
}

// Ư�� ��å �̸��� �ش��ϴ� ��带 ã�Ƽ� ��ȯ�ϴ� �Լ�
static node* find(node* root, const std::string& value) {
	
	if (root == NULL) {		// root�� ���� ���
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



