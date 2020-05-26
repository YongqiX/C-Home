// 链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct E {
	float dm;
	float hp;
	char name[16];
	struct E* next;
}Enemy;
typedef struct {
	int num;
	Enemy* next;
}EnemyLinkedList;
void AddNewEnemy(EnemyLinkedList* head, Enemy* newEnemy) {
	newEnemy->next = head->next;
	head->next = newEnemy;
	head->num++;
}
void RemoveEnemy(EnemyLinkedList *head, Enemy *enemy) {
	Enemy* e = head->next;
	if (e == enemy) {
		head->next = e->next;
		free(e);
		head->num--;
		return;
	}
	while (e->next != enemy && e->next != NULL)
		e = e->next;
	if (e->next == enemy) {
		Enemy* tmp = e->next->next;
		free(e->next);
		e->next = tmp;
		head->num--;
	}
}
Enemy* FindByName(EnemyLinkedList* head, char* name) {
	Enemy* p = head->next;
	while (p != NULL && strcmp(p->name, name) != 0)
		p = p->next;
	return p;
}
Enemy* SortByDM(Enemy* first) {
	if (first == NULL || first->next == NULL)
		return first;
	Enemy* minPre = first;
	Enemy* e = first->next;
	while (e->next != NULL) {
		if (e->next->dm < minPre->next->dm)
			minPre = e;
		e = e->next;
	}
	if (minPre->next->dm < first->dm) {
		e = minPre->next;
		minPre->next = e->next;
		e->next = first;
		first = e;
	}
	first->next = SortByDM(first->next);
	return first;
}
void Print(EnemyLinkedList* head) {
	Enemy* e = head->next;
	while (e != NULL) {
		printf("%s,%.0f,%.0f\t", e->name, e->dm, e->hp);
		e = e->next;
	}
	printf("\n");
}
void Destroy(EnemyLinkedList* head) {
	Enemy* e = head->next;
	Enemy* q = e->next;
	while (q != NULL) {
		q = e->next;
		free(e);
		e = q;
	}
	free(head);
}

int main()
{
	srand(time(NULL));
	EnemyLinkedList* head = (EnemyLinkedList*)malloc(sizeof(EnemyLinkedList));
	head->next = NULL;
	head->num = 0;
	int nCand = rand() % 20;
	char* find = NULL;
	for (int i = 0; i < 20; i++) {
		Enemy* e = (Enemy*)malloc(sizeof(Enemy));
		e->dm = (rand() % 100+1);
		e->hp = (rand() % 100+1);
		e->name[0] = 'A' + rand() % 26;
		e->name[1] = 'A' + rand() % 26;
		e->name[2] = 'A' + rand() % 26;
		e->name[3] = '\0';
		AddNewEnemy(head, e);
		if (nCand == i)
			find = e->name;
	}
	Print(head);
	Enemy* p = FindByName(head, find);
	printf("The Enemy found:name:%s,dm:%.0f\n", p->name, p->dm, p->hp);
	RemoveEnemy(head, p);
	printf("从链表删除一个敌人\n");
	Print(head);
	printf("按照伤害值排序\n");
	head->next = SortByDM(head->next);
	Print(head);
	Destroy(head);
	return 0;
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
