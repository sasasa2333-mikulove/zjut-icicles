#pragma once
typedef int dataType; //���������������intΪ��
using namespace std;
class node {
public:
	node(dataType d, node* ptr = nullptr) { data = d; next = ptr; }
	dataType data;
	node* next;
};
node* buildListForward()//�Ӽ��������������ݣ����򹹽��������ر��ס�
{
    dataType xdata;//�����������ʱ����
    cin >> xdata;
    node* head = new node(xdata), * tail = head, * Nnode; //������һ����㣬���׺ͱ�βָʾͬһ�����
    char c;
    while ((cin >> xdata).get(c)) //ʹ�� cin ����ѭ��
    {
        Nnode = new node(xdata); //�����½��ռ�
        tail->next = Nnode; //���½��ҽ��ڱ�β
        tail = Nnode; //�½���Ϊ�±�β
        if (c == '\n') break;
    }
    return head;
}
node* buildListReverse()//�Ӽ��������������ݣ����򹹽��������ر��ס�
{
    dataType xdata;
    node* head = NULL, * Nnode; //������һ����㣬���׺ͱ�βָʾͬһ�����
    char c;
    while ((cin >> xdata).get(c)) //ʹ�� cin ����ѭ����������Ϊ�� dataType ���ͻ��� Ctrl+Z ����
    {
        Nnode = new node(xdata); //�����½��ռ�
        Nnode->next = head;
        head = Nnode; //�½���Ϊ�±���
        if (c == '\n') break;
    }
    return head;
}
void display(node* xhead)//���ݱ������η������������ݣ��������ʹ�ö��ŷָ���
{
    node* p = xhead; //����ָ�����pָ�����
    if (p != NULL)
    {
        cout << p->data;
        p = p->next;
        while (p != NULL)//��pΪ��ʱ��������ʽ���
        {
            cout << "," << p->data;
            p = p->next;//pָ����һ�����
        }
        cout << endl;
    }

}
void search(node* xhead, dataType value, node*& p, node*& pre)//����Ŀ��ֵvalue���ڸ������׵������в���value��λ��p�Լ�ǰ����pre
{
    p = xhead; //����ָ�����pָ�����
    pre = NULL;//����ָ�����preָ��ս��
    while (p != NULL && p->data != value)//��pΪ�ջ���p��ָ���ݲ�����Ŀ��ֵʱ�����ҽ���
    {
        pre = p;//��pǰ����㸳ֵ��pre
        p = p->next;//pָ����һ�����
    }
}
void deleteList(node*& xhead)//���ݸ����ı��׻�����������н��
{
    node* p = xhead, * q; //����ָ�����pָ����ף�qΪ��ʱָ��
    while (p != NULL)//��pΪ��ʱ��������ʽ���
    {
        q = p;//��p��㸳ֵ��q
        p = p->next;//pָ����һ�����
        delete q;//����q��ָ���ռ�
    }
    xhead = NULL;//ͬ�����±���
}
void add2tail(node*& xhead, node*& xtail, dataType value)//���ݸ�����value�������½�㲢������ӵ������β��
{
    node* newNode = new node(value);
    if (!xhead) {
        xhead = newNode;
        xtail = newNode;
    }
    else {
        xtail->next = newNode;
        xtail = newNode;
    }
}
void add2head(node*& xhead, node*& xtail, dataType value)//���ݸ�����value�������½�㲢������ӵ�������ײ�
{
    node* Nnode = new node(value); //�����½��ռ�
    Nnode->next = xhead;
    xhead = Nnode;//�½���Ϊ�±���
}
node* findListTail(node* head)//���ݱ����ҵ���������һ����㣨β����������
{
    node* p = head, * q = NULL; //����ָ�����pָ����ף�qΪ��ʱָ��
    while (p != NULL)//��pΪ��ʱ��������ʽ���
    {
        q = p;//��p��㸳ֵ��q
        p = p->next;//pָ����һ�����
    }
    return q;//���ر�β
}



void addAfterP(node*& xhead, node* p, dataType value)
{
    node* Nnode = new node(value);
    if (p == NULL)
    {
        Nnode->next = xhead;
        xhead = Nnode;
    }
    else
    {
        Nnode->next = p->next;
        p->next = Nnode;
    }
}
void addBeforeP(node*& xhead, node* pre, node* p, dataType value)
{
    node* Nnode = new node(value, p);
    if (p == NULL)
    {
        Nnode->next = xhead;
        xhead = Nnode;
    }
    else
    {
        if (pre == NULL)
        {
            xhead = Nnode;
        }
        else  pre->next = Nnode;
    }
}
void deleteP(node*& xhead, node* pre, node* p)
{
    if (p == xhead)
    {
        xhead = p->next;
        delete p;
    }
    else
    {
        pre->next = p->next;
        delete p;
        p = pre->next;
    }
}
void add2OrderedList(node*& xhead, dataType value)
{
    node* Nnode = new node(value);
    if (xhead == NULL)
    {
        xhead = Nnode;
    }
    else if (xhead->next == NULL)
    {
        if (xhead->data <= value)
        {
            xhead->next = Nnode;
        }
        else
        {
            Nnode->next = xhead;
            xhead = Nnode;
        }
    }
    else if (xhead->data > value)
    {
        Nnode->next = xhead;
        xhead = Nnode;
    }
    else
    {
        node* pre = xhead;
        node* p = xhead->next;
        while (p != NULL)
        {
            if (p->data > value)
            {
                Nnode->next = p;
                pre->next = Nnode;
                break;
            }
            p = p->next;
            pre = pre->next;
        }
        pre->next = Nnode;
    }
}
void reverseList(node*& xhead)
{
    if (xhead != NULL && xhead->next != NULL)
    {
        node* p = xhead->next;
        node* pre = xhead;
        node* s = p->next;
        while (p != NULL)
        {
            p->next = pre;
            pre = p;
            p = s;
            if (s != NULL) s = s->next;

        }
        xhead->next = NULL;
        xhead = pre;
    }
}
node* copyList(node* xhead)
{
    if (xhead != NULL)
    {
        node* head = new node(xhead->data);
        node* tail = head;
        node* p = xhead->next;
        while (p != NULL)
        {
            node* Nnode = new node(p->data);
            tail->next = Nnode;
            tail = Nnode;
            p = p->next;
        }
        return head;
    }
    return NULL;
}
void selectSortList(node* xhead)
{
    if (xhead != NULL)
    {
        node* p, * pre = xhead;

        while (pre->next != NULL)
        {
            node* min = pre;
            p = pre->next;
            while (p != NULL)
            {
                if (p->data < min->data)
                {
                    min = p;
                }
                p = p->next;
            }
            dataType d = pre->data;
            pre->data = min->data;
            min->data = d;
            pre = pre->next;
        }
    }
}
void bubbleSortList(node* xhead)
{
    if (xhead != NULL)
    {
        node* p, * pt;
        node* pre = xhead;
        while (pre != NULL)
        {
            p = xhead;
            pt = p->next;
            while (pt != NULL)
            {
                if (p->data > pt->data)
                {
                    dataType d = p->data;
                    p->data = pt->data;
                    pt->data = d;
                }
                p = pt;
                pt = pt->next;
            }
            pre = pre->next;
        }

    }
}
void deleteAllValues(node*& xhead, dataType value)
{
    if (xhead != NULL)
    {
        node* p = xhead;
        node* pt = xhead->next;
        while (xhead->data == value)
        {
            delete p;
            xhead = pt;
            if (xhead == NULL) break;
            p = pt;
            pt = pt->next;
        }

        while (pt != NULL)
        {
            if (pt->data == value)
            {
                p->next = pt->next;
                delete pt;
                pt = p->next;
            }
            else
            {
                p = p->next;
                pt = pt->next;
            }
        }
    }
}
