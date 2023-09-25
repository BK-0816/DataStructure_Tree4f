#include <stdio.h>
#define true 1
#define false 0
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread; //���� ������ ��ũ�� �������̸� TRUE
} TreeNode;

TreeNode* find_successor(TreeNode* p)
{
	// q�� p�� ������ ������
	TreeNode* q = p->right;
	// ���� ������ �����Ͱ� NULL�̰ų� �������̸� ������ �����͸� ��ȯ
	if (q == NULL || p->is_thread == true)
		return q;

	// ���� ������ �ڽ��̸� �ٽ� ���� ���� ���� �̵�
	while (q->left != NULL) q = q->left;
	return q;
}
void thread_inorder(TreeNode* t)
{
	TreeNode* q;

	q = t;

	while (q->left) q = q->left;// ���� ���� ���� ����.
	do
	{
		printf("%d ", q->data);// ������ ���
		q = find_successor(q); // �ļ��� �Լ� ȣ��
	} while (q);			// NULL�� �ƴϸ�
}

//		  1
//	  2		  7
//  3   6   8    9
//4   5        10 11 
TreeNode n1 = { 4, NULL, NULL,1 };
TreeNode n2 = { 5, NULL, NULL,1 };
TreeNode n3 = { 3, &n1, &n2,0 };
TreeNode n4 = { 6, NULL, NULL,1 };
TreeNode n5 = { 2, &n3, &n4,0 };
TreeNode n6 = { 8, NULL, NULL,1 };
TreeNode n7 = { 10, NULL, NULL,1 };
TreeNode n8 = { 11, NULL, NULL,0 };
TreeNode n9 = { 9, &n7, &n8,0 };
TreeNode n10 = { 7, &n6, &n9,0 };
TreeNode n11 = { 1, &n5, &n10,0 };
TreeNode* exp = &n11;

TreeNode* parent(TreeNode* child)
{
	if (child == NULL || child == exp)
		return NULL;

	if (child->right != NULL)
		return child->right;
}
int main() {
	n1.right = &n3;
	n2.right = &n5;
	n4.right = &n11;
	n6.right = &n10;
	n7.right = &n9;
	printf("1.���� ��ȸ ���\n");
	printf("\n");
	thread_inorder(exp);
	printf("\n");

	// ��� 4, 5, 6�� �θ� ��� ã�� �� ���
	TreeNode* parent_of_4 = parent(&n1);
	TreeNode* parent_of_5 = parent(&n2);
	TreeNode* parent_of_6 = parent(&n4);

	printf("Parent of 4: %d\n", parent(&n1));
	printf("Parent of 5: %d\n", parent(&n2));
	printf("Parent of 6: %d\n", parent(&n4));

	return 0;
}