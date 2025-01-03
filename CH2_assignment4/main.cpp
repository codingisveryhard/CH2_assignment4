#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std; // namespace std 사용
// 책의 이름과 작가를 저장한다
class Book {    
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
};

class BorrowManager {
private:
    unordered_map<string, int> stock; // 맵 타입으로 책의 이름과 재고를 정한다
public:
    // 맵에 책의 이름과 수량을 추가한다
    void initializeStock(string book, int quantity = 3) {   
        stock[book] = quantity;
    }
    // 책을 대여한다.
    void borrowBook(string title) {     
        if (stock[title] > 0) {
            stock[title]--;
            cout << "책을 대여하였습니다.  재고 수: " << stock[title] << endl;
        }
        else cout << "더이상 대여할 책이 없습니다." << endl;

    }
    // 대여한 책을 반납한다.
    void returnBook(string title) {     
        if (stock[title] < 3) {
            stock[title]++;
            cout << "책이 반납되었습니다.  재고 수: " << stock[title] << endl;
        }
        else cout << "반납될 책이 없습니다." << endl;
    }
    // 현재 책의 재고 목록을 보여준다
    void displayStock() {               
        for (auto i = stock.begin(); i != stock.end(); i++) {
            cout << "책의 제목: " << i->first << " 재고 수: " << i->second << endl;
        }
    }
    // 재고 수량을 표시하기 위해 추가한 메서드
    int getstock(string title) {        
        return stock[title];
    }

};

class BookManager {
private:
    vector<Book> books; // 책을 벡터 컨테이너에 저장한다

public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back 사용
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    }

    // 모든 책 출력 메서드
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    // 책 제목 검색 메서드
    void searchByTitle(const string& title) {
        int count = -1;
        for (size_t i = 0; i < books.size(); i++) { //for문을 통해 책의 위치 탐색
            if (books[i].title == title) count = i;
        }
        if (count == -1) cout << "도서관에 없는 제목의 책입니다." << endl;   // 일치하는 책이 없을 시 출력
        else cout << "- " << books[count].title << " by " << books[count].author << endl; // 일치하는 책이 있을 시 책의 제목과 작가를 출력
    }

    //  책 작가 검색 메서드
    void searchByAuthor(const string& author) {
        int count = 0;
        for (size_t i = 0; i < books.size(); i++) { //for문을 통해 책의 위치 탐색
            if (books[i].author == author) count = i;
        }
        if (count == -1) cout << "도서관에 없는 제목의 책입니다." << endl;   // 일치하는 책이 없을 시 출력
        else cout << "- " << books[count].title << " by " << books[count].author << endl; // 일치하는 책이 있을 시 책의 제목과 작가를 출력
    }
    // 작가를 통해 책의 이름을 찾기 위해 추가한 메서드
    string getTitle(const string& author) {         
        string title;
        for (size_t i = 0; i < books.size(); i++) { //for문을 통해 책의 위치 탐색
            if (books[i].author == author) {
                title = books[i].title;
                break;
            }
        }
        return title;
    }

};


int main() {
    BookManager manager;
    BorrowManager borrowManager;    // 대여기능을 따로 쓰기 위해 추가로 객체를 생성

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 제목으로 책 검색 및 대여" << endl;    // 책을 검색 후 대여 여부를 결정
        cout << "4. 작가로 책 검색 및 대여" << endl;      // 작가로 검색 후 대여 여부를 결정
        cout << "5. 반납하기" << endl;                    // 대여한 책을 반납
        cout << "6. 종료" << endl; // 프로그램 종료
        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (choice == 1) {
            // 1번 선택: 책 추가
            // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
            string title, author;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            manager.addBook(title, author); // 입력받은 책 정보를 추가
            borrowManager.initializeStock(title, 3);    // 입력받은 책을 대여목록에 추가
        }
        else if (choice == 2) {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            // 3번 선택: 제목으로 책 검색
            // 현재 BookManager에 저장된 책 목록에서 검색합니다
            string title;
            string YN;
            cout << "검색할 도서의 이름: ";
            cin.ignore();
            getline(cin, title);
            manager.searchByTitle(title);
            cout << "재고 현황: " << borrowManager.getstock(title) << endl;   // 재고 현황을 출력
            cout << "대여하시겠습니까? (y or n)" << endl;
            cin >> YN;
            if (YN == "y") {
                borrowManager.borrowBook(title);        // 입력받은 title을 통해 대여
            }
            else if (YN == "n") {
                cout << "대여하지 않습니다." << endl;
            }
            else cout << "잘못된 입력입니다." << endl;
        }
        else if (choice == 4) {
            // 3번 선택: 작가로 책 검색
            // 현재 BookManager에 저장된 책 목록에서 검색합니다.
            string author;
            string YN;
            cout << "검색할 작가의 이름: ";
            cin.ignore();
            getline(cin, author);
            manager.searchByAuthor(author);
            cout << "재고 현황: " << borrowManager.getstock(manager.getTitle(author)) << endl;    // 입력받은 작가를 통해 제목을 얻어내서 대여
            cout << "대여하시겠습니까? (y or n)" << endl;
            cin >> YN;
            if (YN == "y") {
                borrowManager.borrowBook(manager.getTitle(author));
            }
            else if (YN == "n") {
                cout << "대여하지 않습니다." << endl;
            }
            else cout << "잘못된 입력입니다." << endl;
        }
        else if (choice == 5) {
            string title;
            cout << "어떤 책을 반납하시겠습니까?" << endl;
            borrowManager.displayStock();
            cout << "반납할 책의 이름: ";
            cin.ignore();
            getline(cin, title);
            borrowManager.returnBook(title);    // 책을 반납한다.
        }
        else if (choice == 6) {
            // 3번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0; // 프로그램 정상 종료
}
