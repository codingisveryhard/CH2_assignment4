#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; // namespace std ���

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

class BookManager {
private:
    vector<Book> books; // å ��� ����

public:
    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    // å ���� �˻� �޼���
    void searchByTitle(const string& title) {
        int count = -1;
        for (size_t i = 0; i < books.size(); i++) { //for���� ���� å�� ��ġ Ž��
            if (books[i].title == title) count = i;
        }
        if (count == -1) cout << "�������� ���� ������ å�Դϴ�." << endl;   // ��ġ�ϴ� å�� ���� �� ���
        else cout << "- " << books[count].title << " by " << books[count].author << endl; // ��ġ�ϴ� å�� ���� �� å�� ����� �۰��� ���
    }

    //  å �۰� �˻� �޼���
    void searchByAuthor(const string& author) {
        int count = 0;
        for (size_t i = 0; i < books.size(); i++) { //for���� ���� å�� ��ġ Ž��
            if (books[i].author == author) count = i;
        }
        if (count == -1) cout << "�������� ���� ������ å�Դϴ�." << endl;   // ��ġ�ϴ� å�� ���� �� ���
        else cout << "- " << books[count].title << " by " << books[count].author << endl; // ��ġ�ϴ� å�� ���� �� å�� ����� �۰��� ���
    }
};

int main() {
    BookManager manager;

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. �������� å �˻�" << endl;
        cout << "4. �۰��� å �˻�" << endl;
        cout << "5. ����" << endl; // ���α׷� ����
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if (choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
        }
        else if (choice == 2) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            // 3�� ����: �������� å �˻�
            // ���� BookManager�� ����� å ��Ͽ��� �˻��մϴ�
            string title;
            cout << "�˻��� ������ �̸�: ";
            cin.ignore();
            getline(cin, title);
            manager.searchByTitle(title);
        }
        else if (choice == 4) {
            // 3�� ����: �۰��� å �˻�
            // ���� BookManager�� ����� å ��Ͽ��� �˻��մϴ�.
            string author;
            cout << "�˻��� �۰��� �̸�: ";
            cin.ignore();
            getline(cin, author);
            manager.searchByAuthor(author);
        }
        else if (choice == 5) {
            // 3�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}
