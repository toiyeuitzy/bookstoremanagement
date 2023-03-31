#include <iostream>
#include <fstream>	
#include <string>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <ctime>
#include <iomanip>	
#include <cstdlib>	

using namespace std;

template <typename properties>

// Hàm để kẻ các cột
void Draw_columns(properties property, int num){
    cout << "|" << left << setw(num) << property << "|";
}

// Hàm để kẻ các hàng
void Draw_rows(int num){
    cout << endl;
    for (int i=0;i<num;i++)
        cout << "=";
}

// Hàm dừng xem màn hình
void Press_to_continue() {
    cout << "\nPress any key to continue...";
    int key = _getch();
    system("CLS");
}

// Đối tượng sách
class Book {
private:
    string isbn;
    string title;
    string author;
    string genre;
    string publisher;
    string year;
    int quantity = 0;
    double price = 0;
public:
    Book() {
    };
    Book(string isbn, string title, string author, string genre, string publisher, string year, int quantity, double price) {
        this->isbn = isbn;
        this->title = title;
        this->author = author;
        this->genre = genre;
        this->publisher = publisher;
        this->year = year;
        this->quantity = quantity;
        this->price = price;
    }
    string getIsbn() {
        return isbn;
    }
    string getTitle() {
        return title;
    }
    string getAuthor() {
        return author;
    }
    string getGenre() {
        return genre;
    }
    string getPublisher() {
        return publisher;
    }
    string getYear() {
        return year;
    }
    int getQuantity() {
        return quantity;
    }
    double getPrice() {
        return price;
    }

    void setIsbn(string i) {
        isbn = i;
    }
    void setTitle(string t) {
        title = t;
    }
    void setAuthor(string a) {
        author = a;
    }
    void setGenre(string g) {
        genre = g;
    }
    void setPublisher(string pl) {
        publisher = pl;
    }
    void setYear(string y) {
        year = y;
    }
    void setQuantity(int q) {
        quantity = q;
    }
    void setPrice(double p) {
        price = p;
    }

    // Phương thức hiển thị thông tin sách
    void display() {
        Draw_columns(isbn,14); 
        Draw_columns(title,20); 
        Draw_columns(author,30); 
        Draw_columns(genre,10); 
        Draw_columns(publisher,25);
	    Draw_columns(year,12);
	    Draw_columns(quantity,8);
	    Draw_columns(price,8); 
	    cout << endl;
    }
};

// Đối tượng quán lý sách
class BookManager {
private:
    vector<Book> books;
public:
    BookManager() {
        // Khởi tạo giá trị ban đầu cho class Book
        Book book1("9780747532743", "Harry Potter 1", "J K Rowling", "Fantasy", "Fahasa", "2020", 100, 120000);
        Book book2("9782070408504", "Hoang Tu Be", "Antoine de Saint-Exupéry", "Novel", "Fahasa", "1969", 100, 136000);
        Book book3("9780199536061", "Anna Karenina", "Lev Tolsoy", "Realistic", "Fahasa", "1877", 158, 139000);
        // Thêm các đối tượng Book vào vector books
        books.push_back(book1);
        books.push_back(book2);
        books.push_back(book3);
    }
    // Phương thức thêm sách mới
    void addBook() {
        string isbn, title, author, genre, publisher, year;
        int  quantity;
        double price;
        cin.ignore();

        cout << "Nhap vao ma ISBN: ";
        getline(cin, isbn);

        cout << "Nhap vao tieu de sach: ";
        getline(cin, title);

        cout << "Nhap vao ten tac gia: ";
        getline(cin, author);

        cout << "Nhap vao the loai sach: ";
        getline(cin, genre);

        cout << "Nhap vao nha xuat ban: ";
        getline(cin, publisher);

        cout << "Nhap vao nam xuat ban: ";
        getline(cin, year);

        cout << "Nhap vao so luong: ";
        cin >> quantity;

        cout << "Nhap vao gia: ";
        cin >> price;

        cin.ignore();

        Book book(isbn, title, author, genre, publisher, year, quantity, price);
        books.push_back(book);

        cout << "Them thanh cong!!" << endl;
        Press_to_continue();
    }

    // Phương thức xoá sách
    void deleteBook() {
        if (books.size() == 0) {
            cout << "Khong ton tai sach trong he thong." << endl;
            return;
        }

        string isbnToDelete;
        cout << "Nhap ma ISBN cua sach muon xoa: ";
        cin.ignore();
        getline(cin, isbnToDelete);

        bool bookFound = false;
        for (auto iter = books.begin(); iter != books.end(); ++iter) {
            if (iter->getIsbn() == isbnToDelete) {
                books.erase(iter);
                cout << "Xoa thanh cong!" << endl;
                bookFound = true;
                break;
            }
        }      
        Press_to_continue();
    }

    // Phương thức chỉnh sửa sách
    void editBook() {
        if (books.size() == 0) {
            cout << "Khong ton tai sach trong he thong." << endl;
            return;
        }

        string isbnToEdit;
        cout << "Nhap ma ISBN cua sach muon chinh sua: ";
        cin.ignore();
        getline(cin, isbnToEdit);

        bool bookFound = false;
        for (auto& book : books) {
            if (book.getIsbn() == isbnToEdit) {
                cout << "Nhap ma ISBN moi (hoac an ENTER de giu bo qua: ";
                string newIsbn;
                getline(cin, newIsbn);
                if (!newIsbn.empty()) {
                    book.getIsbn() = newIsbn;
                }

                cout << "Nhap ten sach moi (hoac an ENTER de giu bo qua: ";
                string newTitle;
                getline(cin, newTitle);
                if (!newTitle.empty()) {
                    book.getTitle() = newTitle;
                }

                cout << "Nhap ten tac gia moi (hoac an ENTER de giu bo qua: ";
                string newAuthor;
                getline(cin, newAuthor);
                if (!newAuthor.empty()) {
                    book.getAuthor() = newAuthor;
                }

                cout << "Nhap the loai moi (hoac an ENTER de giu bo qua: ";
                string newGenre;
                getline(cin, newGenre);
                if (!newIsbn.empty()) {
                    book.getGenre() = newGenre;
                }

                cout << "Nhap nha xuat ban moi (hoac an ENTER de giu bo qua: ";
                string newPublisher;
                getline(cin, newPublisher);
                if (!newPublisher.empty()) {
                    book.getIsbn() = newPublisher;
                }

                cout << "Nhap nam xuat ban moi (hoac an ENTER de giu bo qua: ";
                string newYear;
                getline(cin, newYear);
                if (!newYear.empty()) {
                    book.getYear() = newYear;
                }

                cout << "Nhap so luong sach moi (hoac an ENTER de giu bo qua: ";
                string newQuantity;
                getline(cin, newQuantity);
                if (!newQuantity.empty()) {
                    int QuantityValue = stoi(newQuantity);
                    book.setQuantity(QuantityValue);
                }

                cout << "Nhap gia sach noi (hoac an ENTER de giu bo qua ";
                string newPrice;
                getline(cin, newPrice);
                if (!newPrice.empty()) {
                    int PriceValue = stoi(newPrice);
                    book.setPrice(PriceValue);
                }

                cout << "Chinh sua thanh cong!!" << endl;
                bookFound = true;
                break;
            }
        }

        if (!bookFound) {
            cout << "Khong tim thay. Vui long thu lai." << endl;
        }
        Press_to_continue();
    }
    
    // Phương thức tra cứu sách
    void searchBook() {
       if (books.size() == 0) {
            cout << "Khong ton tai sach trong he thong" << endl;
            return;
        }

        string isbnToSearch;
        cout << "Nhap ma ISBN cua sach ban muon tim: ";
        cin.ignore();
        getline(cin, isbnToSearch);
        bool bookFound = false;
        for (auto iter = books.begin(); iter != books.end(); ++iter) {
            if (iter->getIsbn() == isbnToSearch) {
                cout << "\nBOOK FOUND !!!\n" << endl;
                cout << "\nBOOK INFORMATION: \n" << endl;
                iter->display();
                bookFound = true;
                break;
            }
        }

        if (!bookFound) {
            cout << "Khong tim thay. Vui long thu lai." << endl;
        }
        Press_to_continue();
    }

    // Phương thức thêm sách vào hoá đơn
    void addBookforBill(Book &temp, string isbnToSearch, bool &bookFound) {
        bookFound = false;
        for (auto& book : books) {
            if (book.getIsbn() == isbnToSearch) {
                temp = book;
                bookFound = true;
            }
        }
        if (!bookFound) {
            cout << "Khong tim thay sach voi ma isbn: " << isbnToSearch << " .Vui long thu lai." << endl;
        }
    }

    // Hàm so sánh theo Title
    static bool compareByTitle(Book book1, Book book2) {
        return book1.getTitle() < book2.getTitle();
    }
    // Sắp xếp danh sách các đầu sách theo thứ tự tên sách
    void sortByTitle() {
        sort(books.begin(), books.end(), compareByTitle);
        displayBooks();
    }
    //Hàm so sánh theo mã ISBN
    static bool compareByISBN(Book book1, Book book2) {
        return book1.getIsbn() < book2.getIsbn();
    }
    // Sắp xếp danh sách các đầu sách theo thứ tự ISBN
    void sortByISBN() {
        sort(books.begin(), books.end(), compareByISBN);
        displayBooks();
    }
    // Hàm so sánh theo số lượng
    static bool compareByQuantity(Book book1, Book book2) {
        return book1.getQuantity() < book2.getQuantity();
    }
    // Sắp xếp danh sách các đầu sách theo số lượng
    void sortByQuantity() {
        sort(books.begin(), books.end(), compareByQuantity);
        displayBooks();
    }
    // Hàm so sánh theo năm 
    static bool compareByYear(Book book1, Book book2) {
        return book1.getYear() < book2.getYear();
    }
    // Sắp xếp danh sách các đầu sách theo năm
    void sortByYear() {
        sort(books.begin(), books.end(), compareByYear);
        displayBooks();
    }
    // Hàm so sánh theo đơn giá
    static bool compareByPrice(Book book1, Book book2) {
        return book1.getPrice() < book2.getPrice();
    }
    // Sắp xếp danh sách các đầu sách theo đơn giá
    void sortByPrice() {
        sort(books.begin(), books.end(), compareByPrice);
        displayBooks();
    }
    // Phương thức hiển thị tất cả sách
    void displayBooks() {
        if (books.size() == 0) {
            cout << "Khong co sach nao!" << endl;
            return;
        }
        Draw_columns("ISBN",14); 
        Draw_columns("TEN SACH",20); 
        Draw_columns("TAC GIA",30); 
        Draw_columns("THE LOAI",10); 
        Draw_columns("NHA XUAT BAN",25);
	    Draw_columns("NAM XUAT BAN",12);
	    Draw_columns("SO LUONG",8);
	    Draw_columns("GIA TIEN",8); 
        Draw_rows(143);
        for (auto& book : books) {
            cout << endl;
            book.display();
        }
        Press_to_continue();
    }

};

// Hàm hiển thị menu quản lý sách
void bookMenu() {
    BookManager bm;

    int choice = 0;
    int choice2 = 0;
    bool backToMenu = false;
    while (choice != 7) {
        cout << "===================================" << endl;
        cout << "============QUAN LY SACH===========" << endl;
        cout << "1. Them sach moi" << endl;
        cout << "2. Xoa sach" << endl;
        cout << "3. Chinh sua thong tin sach" << endl;
        cout << "4. Tra cuu thong tin sach theo ISBN" << endl;
        cout << "5. Sap xep danh sach" << endl;
        cout << "6. Hien thi danh sach sach" << endl;
        cout << "7. Tro ve menu chinh" << endl;
        cout << "===================================" << endl;
        cout << "Nhap lua chon cua ban: " << endl;
        cin >> choice;
        system("CLS");
        switch (choice) {
        case 1:
            bm.addBook();
            break;
        case 2:
            bm.deleteBook();
            break;
        case 3:
            bm.editBook();
            break;
        case 4:
            bm.searchBook();
            break;    
        case 5:
        while (choice2 != 6) {
            cout << "==================================" << endl;
            cout << "========CHON MOT TIEU CHI=========" << endl;
            cout << "1. Sap xep theo ten" << endl;
            cout << "2. Sap xep theo ma ISBN" << endl;
            cout << "3. Sap xep theo so luong sach" << endl;
            cout << "4. Tra cuu thong tin sach theo nam" << endl;
            cout << "5. Sap xep theo gia" << endl;
            cout << "6. Tro ve menu quan ly sach" << endl;
            cout << "==================================" << endl;
            cout << "Nhap lua chon cua ban: " << endl;
            cin >> choice2;
            system("CLS");
            switch (choice2) {
                case 1:
                    bm.sortByTitle();
                    break;
                case 2:
                    bm.sortByISBN();
                    break;
                case 3:
                    bm.sortByQuantity();
                    break;
                case 4:
                    bm.sortByYear();
                    break;
                case 5:
                    bm.sortByPrice();
                    break;
                case 6:
                    backToMenu = true;
                    break;
                default:
                    cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
                    break;              
            }
            }
            backToMenu = false;
            break;       
        case 6:
            bm.displayBooks();
            break;
        case 7:
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
            break;
        }
    }
}

// Đối tượng khách hàng
class Customer {
private:
    string id;
    string name;
    string gender;
    string birth;
    string address;
    string phone;
public:
    Customer() {};
    Customer(string i, string n, string s, string b, string a, string p) {
        this->id = i;
        this->name = n;
        this->gender = s;
        this->birth = b;
        this->address = a;
        this->phone = p;
    }
    string getId() {
        return id;
    }
    string getName() {
        return name;
    }
    string getGender() {
        return gender;
    }
    string getBirth() {
        return birth;
    }
    string getAddress() {
        return address;
    }
    string getPhone() {
        return phone;
    }
    void setId(string i) {
        id = i;
    }
    void setName(string n) {
        name = n;
    }
    void setGender(string s) {
        gender = s;
    }
    void setBirth(string b) {
        birth = b;
    }
    void setAddress(string a) {
        address = a;
    }
    void setPhone(string p) {
        phone = p;
    }
    // Phương thức hiển thị thông tin khách hàng
    void display() {
        Draw_columns(id,7); 
        Draw_columns(name,20); 
        Draw_columns(gender,10); 
        Draw_columns(birth,12); 
        Draw_columns(address,25);
	    Draw_columns(phone,12);
        cout << endl;
    }
};

// Đối tượng quán lý khách hàng
class CustomerManager {
private:
    vector<Customer> customers;

public:
    CustomerManager() {

        // Khởi tạo giá trị ban đầu cho class Customer
        Customer customer1("KH10001", "Jamal Musiala", "Nam", "28/2/2003", "Berlin", "0346791435");
        Customer customer2("KH10002", "Kim Jisoo", "Nu", "13/8/1999", "Korea", "0257854658");
        Customer customer3("KH10003", "Kim Yoo Jung", "Nu", "23/6/1998", "Korea", "0143484351");
        Customer customer4("KH10004", "Alejandro Garnacho", "Nam", "13/9/1989","Munich, Germany","0836987564");

        // Thêm các đối tượng Customer vào vector customers
        customers.push_back(customer1);
        customers.push_back(customer2);
        customers.push_back(customer3);
        customers.push_back(customer4);
    }

    // Phương thức thêm thông tin khách hàng mới
    void addCustomer() {
        string id, name, gender, birth, address, phone;
        cout << "NHAP VAO THONG TIN CUA KHACH HANG MOI: \n";
        cout << "--------------------------------------\n";
        cin.ignore();

        string tempID = customers.back().getId();
        tempID = tempID.substr(2, 5);
        id = "KH" + to_string(stoi(tempID) + 1);

        cout << "Nhap vao ten khac hang: ";
        getline(cin, name);

        cout << "Nhap vao gioi tinh: ";
        getline(cin, gender);

        cout << "Nhap vao sinh nhat: ";
        getline(cin, birth);
        birth = birth.substr(0, 10);

        cout << "Nhap vao dia chi: ";
        getline(cin, address);

        cout << "Nhap vao so dien thoai: ";
        getline(cin, phone);
        phone = phone.substr(0, 10);

        Customer customer(id, name, gender, birth, address, phone);
        customers.push_back(customer);

        cout << "Customer info added successfully!" << endl;
        Press_to_continue();
    }

    // Phương thức xoá thông tin khách hàng
    void deleteCustomer() {
        if (customers.size() == 0) {
            cout << "Khong ton tai khach hang nao trong he thong." << endl;
            return;
        }

        string idToDelete;
        cout << "Nhap vao id khach hang can xoa: ";
        cin.ignore();
        getline(cin, idToDelete);

        bool CustomerFound = false;
        for (auto iter = customers.begin(); iter != customers.end(); ++iter) {
            if (iter->getId() == idToDelete) {
                customers.erase(iter);
                cout << "Customer deleted successfully!" << endl;
                CustomerFound = true;
                break;
            }
        }

        if (!CustomerFound) {
            cout << "Khong tim thay khach hang. Vui long thu lai." << endl;
        }
        Press_to_continue();
    }

    // Phương thức chỉnh sửa thông tin khách hàng
    void editCustomer() {
        if (customers.size() == 0) {
            cout << "Khong ton tai khach hang nao trong he thong." << endl;
            return;
        }

        string idToEdit;
        cout << "Nhap vao id khach hang can chinh sua ";
        cin.ignore();
        getline(cin, idToEdit);

        bool CustomerFound = false;
        for (auto& customer : customers) {
            if (customer.getId() == idToEdit) {
                cout << "Nhap vao id (hoac an ENTER de giu bo qua): ";
                string newId;
                getline(cin, newId);
                if (!newId.empty()) {
                    customer.setId(newId);
                }

                cout << "Nhap vao ten (hoac an ENTER de giu bo qua): ";
                string newName;
                getline(cin, newName);
                if (!newName.empty()) {
                    customer.setName(newName) ;
                }

                cout << "Nhap vao gioi tinh (hoac an ENTER de giu bo qua): ";
                string newgender;
                getline(cin, newgender);
                if (!newgender.empty()) {
                    customer.setGender(newgender);
                }

                cout << "Nhap vao ngay sinh (hoac an ENTER de giu bo qua): ";
                string newBirth;
                getline(cin, newBirth);
                if (!newBirth.empty()) {
                    customer.setBirth(newBirth);
                }

                cout << "Nhap vao dia chi (hoac an ENTER de giu bo qua): ";
                string newAddress;
                getline(cin, newAddress);
                if (!newAddress.empty()) {
                    customer.setAddress(newAddress);
                }

                cout << "Nhap vao so dien thoai (hoac an ENTER de giu bo qua): ";
                string newPhone;
                getline(cin, newPhone);
                if (!newPhone.empty()) {
                    customer.setPhone(newPhone);
                }

                cout << "Customer info edited successfully!" << endl;
                CustomerFound = true;
                break;
            }
        }

        if (!CustomerFound) {
            cout << "Khong tim thay khach hang. Vui long thu lai." << endl;
        }
        Press_to_continue();
    }

    // Phương thức hiển thị danh sách khách hàng
    void displayCustomers() {
        if (customers.size() == 0) {
            cout << "Khong ton tai khach hang nao trong he thong." << endl;
            return;
        }       
        Draw_columns("ID",7); 
        Draw_columns("TEN",20); 
        Draw_columns("GIOI TINH",10); 
        Draw_columns("NGAY SINH",12); 
        Draw_columns("DIA CHI",25);
	    Draw_columns("SDT",12);
        Draw_rows(98);
        for (auto& customer : customers) {
            cout << endl;
            customer.display();
        }
        Press_to_continue();
    }

    static bool compareByName(Customer cus1, Customer cus2) {
        return cus1.getName() < cus2.getName();
    }

    void sortByName() {
        sort(customers.begin(), customers.end(), compareByName);
        displayCustomers();
    }
};

// Hàm hiển thị menu quản lý khách hàng
void customerMenu() {
    CustomerManager cm;
    int choice = 0;
    while (choice != 6) {
        cout << "=================================" << endl;
        cout << "========QUAN LY KHACH HANG=======" << endl;
        cout << "1. Them khach hang moi" << endl;
        cout << "2. Xoa khach hang" << endl;
        cout << "3. Chinh sua thong tin khach hang" << endl;
        cout << "4. Hien thi danh sach khach hang" << endl;
        cout << "5. Sap xep danh sach theo ten" << endl;
        cout << "6. Tro ve menu chinh" << endl;
        cout << "=================================" << endl;
        cout << "Nhap lua chon cua ban: " << endl;
        cin >> choice;
        system("CLS");
        switch (choice) {
        case 1:
            cm.addCustomer();
            break;
        case 2:
            cm.deleteCustomer();
            break;
        case 3:
            cm.editCustomer();
            break;
        case 4:
            cm.displayCustomers();
            break;
        case 5:
            cm.sortByName();
            break;
        case 6:
            cout << "Tro ve menu chinh!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
            Press_to_continue();
            break;
        }
    }
}

// Đối tượng đơn hàng
class Bill {
    private:
        int stt;
        string NVbanhang;
        string customerName;
        int sosachmua;
        vector <Book> sach;
        vector <int> soluong;
        int price;
        string ngaymua;
    public:
        Bill() {};
        Bill(int stt, string NVbanhang, string customerName, int sosachmua, vector <Book> sach, vector <int> soluong, int price, string ngaymua) {
            this->stt = stt;
            this->NVbanhang = NVbanhang;
            this->customerName = customerName;
            this->sosachmua = sosachmua;
            this->sach = sach;
            this->soluong = soluong;
            this->price = price;
            this->ngaymua = ngaymua;
        }
        int getSTT() {
            return stt;
        }
        string getNVbanhang() {
            return NVbanhang;
        }
        string getcustomerName() {
            return customerName;
        }
        int getsosachmua() {
            return sosachmua;
        }
        int getPrice() {
            return price;
        }
        string getNgaymua() {
            return ngaymua;
        }

        void setSTT(int stt) {
            stt = stt;
        }
        void setNVbanhang(string NVbanhang) {
            NVbanhang = NVbanhang;
        }
        void setCustomerName(string customerName) {
            customerName = customerName;
        }
        void setsosachmua(int sosachmua) {
            sosachmua = sosachmua;
        }
        void setsach(vector <Book> sach) {
            sach = sach;
        }
        void setsoluong(vector <int> sachmua) {
            soluong = soluong;
        }
        void setPrice(long price) {
            price = price;
        }
        void setngaymua(string ngaymua) {
            ngaymua = ngaymua;
        }
        // Phương thức hiển thị bill
        void display() {
            cout << "STT: " << stt << endl;
            cout << "NHAN VIEN BAN HANG: " << NVbanhang << endl;
            cout << "KHACH HANG MUA: " << customerName << endl;
            cout << "SO SACH MUA: " << sosachmua << endl;
            int count = 0;
            for (auto iter = sach.begin(); iter != sach.end(); ++iter) {
                cout << "Sach " << iter->getTitle() << endl;
                cout << "So luong: " << soluong[count] << endl;
                cout << "Don gia: " << iter->getPrice() << endl;
                count++;
            }
            cout << "THANH TIEN : " <<  price << endl;
            cout << "NGAY MUA: " << ngaymua << endl;
        }
        // Phương thức xuất bill ra file
        void printBill() {
            ofstream fo;
	        fo.open("bill.txt", ios::out);
            fo << "MA DON HANG: " << stt << endl;
            fo << "NHAN VIEN BAN HANG: " << NVbanhang << endl;
            fo << "KHACH HANG MUA: " << customerName << endl;
            fo << "SO SACH MUA: " << sosachmua << endl;
            fo << "=============================================" << endl;
            int count = 0;
            fo << "|" << left << setw(5) << "STT" << "|";
            fo << "|" << left << setw(15) << "Sach" << "|";
            fo << "|" << left << setw(9) << "Don gia" << "|";
            fo << "|" << left << setw(8) << "So luong" << "|" << endl;
            fo << "=============================================" << endl;
            for (auto iter = sach.begin(); iter != sach.end(); ++iter) {
                fo << "|" << left << setw(5) << count + 1 << "|";
                fo << "|" << left << setw(15) << iter->getTitle() << "|";
                fo << "|" << left << setw(9) << iter->getPrice() << "|";
                fo << "|" << left << setw(8) << soluong[count] << "|" << endl;
                count++;
            }

            string amount_str = to_string(price);

            string reversed_str;
            for (int i = amount_str.length() - 1; i >= 0; --i) {
                reversed_str += amount_str[i];
            }

            string formatted_str;
            for (int i = 0; i < reversed_str.length(); ++i) {
                if (i % 3 == 0 && i > 0) {
                    formatted_str += '.';
                }
                formatted_str += reversed_str[i];
            }

            string vnd_str;
            for (int i = formatted_str.length() - 1; i >= 0; --i) {
                vnd_str += formatted_str[i];
            }
            fo << "=============================================" << endl;
            fo << "THANH TIEN : " <<  vnd_str << " VND" << endl;
            fo << "NGAY MUA: " << ngaymua << endl;
            cout << "Xuat bill thanh cong!!\n";
            fo.close();
        }
    };

// Đối tượng quản lý đơn hàng.
class BillManager {
private:
    vector<Bill> bills;
int stt;
        string NVbanhang;
        string customerName;
        int sosachmua;
        vector <Book> sach;
        vector <int> soluong;
        int price;
        string ngaymua;
public:
    BillManager() {
        Book book1("9780747532743", "Harry Potter 1", "J K Rowling", "Fantasy", "Fahasa", "2020", 100, 120000);
        Book book2("9782070408504", "Hoang Tu Be", "Antoine de Saint-Exupéry", "Novel", "Fahasa", "1969", 100, 136000);
        Bill bill(1, "L H Viet Quoc", "Musiala", 2, {book1, book2}, {5, 6}, 295256, "26/03/2023");

        bills.push_back(bill);
    }
    // Phương thức tạo một bill
    void addBill(){
        BookManager bm;
        Book temp;
        vector <Book> sach;
        vector <int> soluong;

        string isbn, NVBH, cusName, date;
        int stt, sosachmua, sluong;
        cin.ignore();
        if (bills.empty()) {
            stt = 1;
        }
        else {
            stt = bills.back().getSTT() + 1;
        }
       
        cout << "Enter Nhan vien ban hang: ";
        getline(cin, NVBH);

        cout << "Enter Ten khach hang mua: ";
        getline(cin,cusName);

        cout << "Enter so sach mua: ";
        cin >> sosachmua;
        cin.ignore();

        int price = 0;
        for (int i = 0; i < sosachmua; i++){
            bool Boolean = false;
            while (Boolean == false) {
                cout << "Nhap ma ISBN cua sach: ";
                getline(cin, isbn);
                bm.addBookforBill(temp, isbn, Boolean);
            }    
        sach.push_back(temp);
        cout << "So luong: ";
        cin >> sluong;
        soluong.push_back(sluong);
        price += temp.getPrice() * sluong;
        }
        cin.ignore();
        time_t now = time(0);
        tm *ltm = localtime(&now);
        date = to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900+ltm->tm_year);
        Bill bill(stt, NVBH, cusName, sosachmua, sach, soluong, price, date);
        bills.push_back(bill);

        cout << "Bill added successfully!\n" << endl;
        string choice;
        do {
            cout << "Ban co muon in ra bill khong? " << endl;
            cout << "[Yes]Y\t[No]N\n\n";
            getline(cin, choice);
        } while ((choice != "Y") && (choice != "N"));

        if (choice == "Y") bill.printBill();
        Press_to_continue();
    }
    // Phương thức tạo xoá bill
    void deleteBill() {
        if (bills.size() == 0) {
            cout << "There are no bills in the system." << endl;
            return;
        }

        int stt;
        cout << "Enter the ordinal of bill: ";
        cin >> stt;

        bool billFound = false;
        for (auto iter = bills.begin(); iter != bills.end(); ++iter) {
            if (iter->getSTT() == stt) {
                bills.erase(iter);
                cout << "Customer deleted successfully!" << endl;
                billFound = true;
                break;
            }
        }

        if (!billFound) {
            cout << "Customer not found. Please try again." << endl;
        }
        Press_to_continue();
    }
    // Phương thức in ra bill
    void printBill() {
        if (bills.size() == 0) {
            cout << "There are no bills in the system." << endl;
            return;
        }

        int stt;
        cout << "Enter the ordinal of bill: ";
        cin >> stt;
        bool billFound = false;
        for (auto iter = bills.begin(); iter != bills.end(); ++iter) {
            if (iter->getSTT() == stt) {
                iter->printBill();
                billFound = true;
                break;
            }
        }
    }
    // Phương thức in ra tất cả bill
    void displayBills() {
        if (bills.size() == 0) {
            cout << "There are no bills in the system." << endl;
        }
        else {
            for (auto& bill : bills) {
            cout << "--------------------" << endl;
            bill.display();
            cout << "--------------------" << endl;
        }
        }
        
        Press_to_continue();
    }
};

// Hàm hiển thị menu quản lý bill
void billMenu() {
    BillManager billm;
    int choice = 0;
    while (choice != 6) {
        cout << "==============================" << endl;
        cout << "=======QUAN LY DON HANG=======" << endl;
        cout << "1. Them don hang moi" << endl;
        cout << "2. Xoa don hang" << endl;
        cout << "3. Chinh sua thong tin hoa don" << endl;
        cout << "4. Hien thi danh sach hoa don" << endl;
        cout << "5. In hoa don" << endl;
        cout << "6. Tro ve menu chinh" << endl;
        cout << "==============================" << endl;
        cout << "Nhap lua chon cua ban: " << endl;
        cin >> choice;
        system("CLS");
        switch (choice) {
        case 1:
            billm.addBill();
            break;
        case 2:
            billm.deleteBill();
            break;
        case 4:
            billm.displayBills();
            break;
        case 5:
            billm.printBill();
            break;
        case 6:
            cout << "Tro ve menu chinh!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
            Press_to_continue();
            break;
        }
    }
}

// Hàm main
int main() {
    int choice = 0;
    while (choice != 4) {
        cout << "======================" << endl;
        cout << "=========MENU=========" << endl;
        cout << "1. QUAN LY KHACH HANG" << endl;
        cout << "2. QUAN LY SACH" << endl;
        cout << "3. QUAN LY DON HANG " << endl;
        cout << "4. THOAT" << endl;
        cout << "======================" << endl;
        cout << "NHAP LUA CHON CUA BAN: ";
        cin >> choice;
        system("CLS");
        switch (choice) {
        case 1:
            customerMenu();
            break;
        case 2:
            bookMenu();
            break;
        case 3:
            billMenu();
            break;
        case 4:
            exit(0);
        default:
            cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
            break;
        }
    }
    return 0;
}