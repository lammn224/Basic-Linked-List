#include <iostream>
using namespace std;
struct Node
{
	int value;
	struct Node *next;
};
//Tạo mới 1 Node
Node *Create(int value)
{
	Node *temp;
	temp = new Node;		// cấp phát vùng nhớ cho SLL temp
	temp->next = NULL;	// đầu tiên khai báo node thì node đó chưa có liên kết => con trỏ của nó sẽ trỏ đến NULL
	temp->value = value;
	return temp;
}
//Thêm Node vào danh sách liên kết
//Thêm vào đầu
Node *AddHead(Node *head, int value)
{
	Node *temp = Create(value);
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
	return head;
}
//Thêm vào cuối
Node *AddTail(Node *head, int value)
{
	Node *temp, *p;
	temp = Create(value);
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = temp;
	}
	return head;
}
//Thêm vào vị trí bất kỳ
//Chỉ số chèn bắt đầu từ chỉ số 0
Node *AddAtPos(Node *head, int value, int pos)
{	
	if (pos == 0 || head == NULL)
	{
		AddHead(head, value);
	}
	else
	{
		int i = 1;
		Node *p = head;
		while (p != NULL && i != pos)
		{
			p = p->next;
			i++;
		}
		if (i != pos)
		{
			/*Nếu duyệt hết danh sách lk rồi 
			mà vẫn chưa đến vị trí cần chèn, 
			ta sẽ mặc định chèn cuối */
			head = AddTail(head, value);
		}
		else
		{
			Node *temp = Create(value);
			temp->next = p->next;
			p->next = temp;
		}

	}
	return head;
}

//Xóa node trong danh sách liên kết
//Xóa đầu
Node *DelHead(Node *head)
{
	if (head == NULL)
	{
		cout << "Linked list is empty";
	}
	else 
	{
		head = head->next;
	}
	return head;
}
//Xóa cuối
Node *DelTail(Node *head)
{
	if (head == NULL)
	{
		cout << "Linked list is empty";
	}
	// duyệt đến thằng cuối – 1, cho next của cuối – 1 đó bằng NULL.
	else
	{
		Node *p = head;
		while (p->next->next != NULL)
		{
			p = p->next;
		}
		p->next = NULL;
	}
	return head;
}
//Xóa ở vị trí bất kỳ
Node *DelAtPos(Node *head, int pos)
{
	if (pos == 0)
	{
		head = DelHead(head);
	}
	else
	{
		Node *p = head;
		int k = 1;
		while (p->next->next != NULL && k != pos)
		{
			p = p->next;
		}
		p->next = p->next->next;
	}
	return head;
}

Node* insert(Node* head, int value)
{
	Node* p = head;
	Node* pre = head;
	Node* temp = new Node;
	temp->value = value;
	bool check = true;
	//cout << head->value << " " << head->next->value << endl;
	if (head->value > head->next->value)
	{
		for (; p != NULL; p = p->next)
		{
			if (value > p->value)
			{
				if (p == head)			//neu p la head <-> gan luon vao head
				{
					temp->next = head;
					head = temp;		//doi lai head la temp
					check = false;		// update check
				}
				break;
			}
			pre = p;
		}
		if (check) {			//neu check == false thi ko chay vao TH nay vi da gan vao head
			temp->next = p;
			pre->next = temp;
		}
	}
	else
	{
		for (; p != NULL; p = p->next)
		{
			if (value < p->value)
			{
				if (p == head)
				{
					temp->next = head;
					head = temp;
					check = false;
				}
				break;
			}
			pre = p;
		}
		if (check) {
			temp->next = p;
			pre->next = temp;
		}
	}
	return head;
}
Node* deleteDuplicates(Node* head)
{
	for (Node* p = head; p != NULL; p = p->next)
	{
		Node* prevNode = p;
		for (Node* q = p->next; q != NULL; q = q->next)
		{
			if (p->value == q->value)
			{
				prevNode->next = q->next;
				q = prevNode;
			}
			prevNode = q;
		}
	}
	return head;
}

Node *initHead()
{
	Node *head;
	head = NULL;
	return head;
}

Node *Nhap()
{
	Node *head = initHead();
	int n, value;
	cout << "Nhap so luong phan tu n = ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "nhap gia tri can them: ";
		cin >> value;
		head = AddTail(head, value);
	}
	return head;
}

int Length(Node *head) {
	int length = 0;
	for (Node *p = head; p != NULL; p = p->next) {
		length++;
	}
	return length;
}

void xuat(Node *head)
{
	for (Node *p = head; p != NULL; p = p->next)
	{
		cout << p->value << " ";
	}
	cout << endl;
}
int main()
{
	cout << "khoi tao 1 danh sach lien ket" << endl;
	Node *head = Nhap();
	cout << "Danh sach vua khoi tao la: " << endl;
	xuat(head);

	//cout << "them mot phan tu" << endl;

	//cout << "Nhap mot phan tu can them vao dau danh sach" << endl << "x = ";
	//int x;
	//cin >> x;
	//head = AddHead(head, x);
	//cout << "linked list sau khi them la: " << endl;
	//xuat(head);

	//cout << "Nhap mot phan tu can them vao cuoi danh sach" << endl << "x = ";
	//cin >> x;
	//head = AddTail(head, x);
	//cout << "linked list sau khi them la: " << endl;
	//xuat(head);

	//cout << "Xoa mot phan tu o dau danh sach " << endl;
	//head = DelHead(head);
	//cout << "Xoa mot phan tu o cuoi danh sach " << endl;
	//head = DelTail(head);

	//cout << "linked list sau khi xoa la: " << endl;
	//xuat(head);

	//cout << "chen them mot node vao vi tri bat ki" << endl;
	////head = AddAtPos(head, 45, 3);
	//xuat(head);
	//cout << "head+1 : " << head->next->value << endl;
	//xuat(head);
	cout << "do dai linked list la: " << Length(head) << endl;

	//head = deleteDuplicates(head);
	head = insert(head, 4);
	xuat(head);
	cout << "do dai linked list la: " << Length(head) << endl;


	return 0;
}
