// Используя генератор случайных чисел сформировать бинарное дерево, состоящее из 15 элементов  
// (предусмотреть ручной ввод элементов). Причем числа должны лежать в диапазоне от -99 до 99. 
// Произвести поиск со вставкой и  удалением  элементов в соответствии со следующими вариантами заданий:
// 5. Числа по выбору.
// Зоренко Вікторія ІП-74
#include <stdio.h>
#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) {
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};

class Tree {
  public:
  TreeNode *root;
  Tree() {
    this->root = NULL;
    }

  void push(int val) {
    if (this->root == NULL) {
    this->root = new TreeNode(val);
    return;
    }
    this->pushHelper(this->root, val);
  }

  void print() {
    printf("\n");
    printHelper(this->root, 0);
    printf("\n");
  }

  void find(int N) { //створили функцію пошуку
    this->findHelper(this->root, N); //викликаємо допоміжну функцію
  }

  private:
  TreeNode *minValueNode(TreeNode *r) {
    TreeNode* curr = r;
    while (curr->left != NULL) curr = curr->left;
    return curr;
  }
  
void deleteValHelper(TreeNode *&r, int val){
  if (r == NULL) return;
  if (val < r->val) {
   deleteValHelper(r->left, val);
   return;
  }
  else if (val > r->val) {
   deleteValHelper(r->right, val);
   return;
  }
  if (r->left == nullptr && r->right == nullptr) {
   delete r;
   r = nullptr;
  }
  else if (r->left == nullptr) {
   TreeNode *tmp = r;
   r = r->right;
   delete tmp;
  }
  else if (r->right == nullptr) {
   TreeNode *tmp = r;
   r = r->left;
   delete tmp;
  }
  else {
   TreeNode *tmp = minValueNode(r->right);
   r->val = tmp->val;
   deleteValHelper(r->right, tmp->val);
  }
  return;
 }


void findHelper(TreeNode *r, int N) {
    if (r == NULL) {
      return;  //якщо дерева не існує виходимо
    }
    if (r->left != NULL) { //якщо існує лівий нащадок йдемо в нього
      findHelper(r->left, N); //викликаємо функцію для нащадку
    }
    if (r->right != NULL) { //якщо існує правий нащадок йдемо в нього
      findHelper(r->right, N); //викликаємо функцію для нащадку
    } 
    if (r->val == N) { //якщо значення відповідає умові задачі
      deleteValHelper(this->root, r->val); //викликаємо функцію видалення(пояснювала при здачі лаби)
    }
}
  
void printHelper(TreeNode* r, int level) {
    if (r == NULL) return;
    printHelper(r->right, level + 1);
    for (int i = 0; i < level; i++) {
      printf(" ");
    }
    printf("%d\n", r->val);
    printHelper(r->left, level + 1);
}

void pushHelper(TreeNode *r, int val) {
		TreeNode** direction = NULL;
		if (val > r->val) {
			if (r->right != NULL) {
				pushHelper(r->right, val);
				return;
			}
			r->right = new TreeNode(val);
		}
		else if(val < r->val){
			if (r->left != NULL) {
				pushHelper(r->left, val);
				return;
			}
			r->left = new TreeNode(val);
		}
		else return;
	}
};

int main() {
  bool number = false;
  int fill;
  Tree *tree = new Tree();
  while (!number) {
    cout << "How do you want to fill the binary tree?\n"
			<< "1 - randomly\n"
			<< "2 - by yourself\n";
		cin >> fill; 
    if ( fill == 1 ) {
      for ( int i = 0; i < 15; i++) {
        tree->push(rand() % 199 - 98);
        }
      number = true;
    } else if (fill == 2) {
      cout << "Add by yourself\n";
      int add;
      cout << "If you write the same values, they will not be added to the tree\n";      
      for (int i = 0; i < 15; i++) {
        cout << i << " element: ";
        cin >> add;
        tree->push(add);
      }
      number = true;
    } else {
      cout << "Wrong number\n";
    }
  }
  tree->print();
  int del;
  cout << "Do you want delete element? 1 = Yes. 2 = No\n";
  cin >> del;
  if (del == 1) {
    cout << "How many items do you want to give? (no more than 15)\n";
    int a; 
    cin >> a;
    if (a < 0 || a > 15) {
        cout << "Sorry, wrong number, bye\n";
        return 0;
    } 
    for (int i = 0; i < a; i++) {
        cout << "Enter the value which you want to delete. If there is no such value to the tree, nothing will be deleted\n";
        int toDel;
        cin >> toDel;
        tree->find(toDel);
    }
    } else if (del == 2) {
        cout << "Ok, see your tree again and bye\n";
        } else {
            cout << "Sorry, wrong number, bye\n";
            return 0;
            }
  tree->print();
  return 0;
}