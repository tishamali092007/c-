#include<iostream>
#include<string>
using namespace std;

class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t="", string a="", string d="")
        : title(t), author(a), dueDate(d) {}

    virtual ~LibraryItem() {}

    string getTitle()   const { return title; }
    string getAuthor()  const { return author; }
    string getDueDate() const { return dueDate; }

    void setTitle(string t)   { title = t; }
    void setAuthor(string a)  { author = a; }
    void setDueDate(string d) { dueDate = d; }

    virtual void checkOut()             = 0;
    virtual void returnItem()           = 0;
    virtual void displayDetails() const = 0;
    virtual string getType()      const = 0;
};

class Book : public LibraryItem
{
    int  pages;
    bool issued;

public:
    Book() : pages(0), issued(false) {}

    void setPages(int p)
    {
        if (p < 0) throw invalid_argument("Pages cannot be negative.");
        pages = p;
    }

    void checkOut() override
    {
        if (issued) cout << "  Book already checked out.\n";
        else { issued = true;  cout << "  Book \"" << getTitle() << "\" checked out. Due: " << getDueDate() << "\n"; }
    }

    void returnItem() override
    {
        if (!issued) cout << "  Book was not checked out.\n";
        else { issued = false; cout << "  Book \"" << getTitle() << "\" returned successfully.\n"; }
    }

    void displayDetails() const override
    {
        cout << "  [Book]\n";
        cout << "  Title   : " << getTitle()   << "\n";
        cout << "  Author  : " << getAuthor()  << "\n";
        cout << "  Due Date: " << getDueDate() << "\n";
        cout << "  Pages   : " << pages        << "\n";
        cout << "  Status  : " << (issued ? "Checked Out" : "Available") << "\n";
    }

    string getType() const override { return "Book"; }
};

class DVD : public LibraryItem
{
    int  duration;
    bool issued;

public:
    DVD() : duration(0), issued(false) {}

    void setDuration(int d)
    {
        if (d < 0) throw invalid_argument("Duration cannot be negative.");
        duration = d;
    }

    void checkOut() override
    {
        if (issued) cout << "  DVD already checked out.\n";
        else { issued = true;  cout << "  DVD \"" << getTitle() << "\" checked out. Due: " << getDueDate() << "\n"; }
    }

    void returnItem() override
    {
        if (!issued) cout << "  DVD was not checked out.\n";
        else { issued = false; cout << "  DVD \"" << getTitle() << "\" returned successfully.\n"; }
    }

    void displayDetails() const override
    {
        cout << "  [DVD]\n";
        cout << "  Title    : " << getTitle()   << "\n";
        cout << "  Director : " << getAuthor()  << "\n";
        cout << "  Due Date : " << getDueDate() << "\n";
        cout << "  Duration : " << duration     << " mins\n";
        cout << "  Status   : " << (issued ? "Checked Out" : "Available") << "\n";
    }

    string getType() const override { return "DVD"; }
};

class Magazine : public LibraryItem
{
    int  issueNo;
    bool issued;

public:
    Magazine() : issueNo(0), issued(false) {}

    void setIssue(int i)
    {
        if (i < 0) throw invalid_argument("Issue number cannot be negative.");
        issueNo = i;
    }

    void checkOut() override
    {
        if (issued) cout << "  Magazine already checked out.\n";
        else { issued = true;  cout << "  Magazine \"" << getTitle() << "\" checked out. Due: " << getDueDate() << "\n"; }
    }

    void returnItem() override
    {
        if (!issued) cout << "  Magazine was not checked out.\n";
        else { issued = false; cout << "  Magazine \"" << getTitle() << "\" returned successfully.\n"; }
    }

    void displayDetails() const override
    {
        cout << "  [Magazine]\n";
        cout << "  Title     : " << getTitle()   << "\n";
        cout << "  Publisher : " << getAuthor()  << "\n";
        cout << "  Due Date  : " << getDueDate() << "\n";
        cout << "  Issue No. : " << issueNo      << "\n";
        cout << "  Status    : " << (issued ? "Checked Out" : "Available") << "\n";
    }

    string getType() const override { return "Magazine"; }
};

const int MAX_ITEMS = 10;

class Library
{
    LibraryItem* items[MAX_ITEMS];
    int count;

public:
    Library() : count(0) {}

    ~Library()
    {
        for (int i = 0; i < count; i++) delete items[i];
    }

    void addItem(LibraryItem* item)
    {
        if (count >= MAX_ITEMS) { cout << "  Catalog is full!\n"; return; }
        items[count++] = item;
        cout << "  Item added successfully!\n";
    }

    void displayAll()
    {
        if (count == 0) { cout << "  No items in catalog.\n"; return; }
        cout << "\n  Total Items: " << count << "\n";
        for (int i = 0; i < count; i++) {
            cout << "\n  [" << i << "] ";
            items[i]->displayDetails();     
            cout << "  " << string(30, '-') << "\n";
        }
    }

    void checkOut(int idx)
    {
        if (idx < 0 || idx >= count) { cout << "  Invalid index.\n"; return; }
        items[idx]->checkOut();             
    }

    void returnItem(int idx)
    {
        if (idx < 0 || idx >= count) { cout << "  Invalid index.\n"; return; }
        items[idx]->returnItem();            
    }

    void searchByTitle(string title)
    {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (items[i]->getTitle() == title) {
                cout << "\n  Found at index [" << i << "]:\n  ";
                items[i]->displayDetails();
                found = true;
            }
        }
        if (!found) cout << "  \"" << title << "\" not found.\n";
    }
};

int main()
{
    Library library;
    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "      LIBRARY MANAGEMENT SYSTEM\n";
        cout << "========================================\n";
        cout << "  1. Add Book\n";
        cout << "  2. Add DVD\n";
        cout << "  3. Add Magazine\n";
        cout << "  4. Show All Items\n";
        cout << "  5. Check Out\n";
        cout << "  6. Return Item\n";
        cout << "  7. Exit\n";
        cout << "  Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Book* b = new Book();
            string t, a, d; int p;
            cout << "  Title  : "; cin >> t;
            cout << "  Author : "; cin >> a;
            cout << "  Due    : "; cin >> d;
            cout << "  Pages  : "; cin >> p;
            try   { b->setPages(p); }
            catch (invalid_argument& e) { cout << "  Error: " << e.what() << "\n"; delete b; continue; }
            b->setTitle(t); b->setAuthor(a); b->setDueDate(d);
            library.addItem(b);
        }
        else if (choice == 2)
        {
            DVD* dv = new DVD();
            string t, a, d; int dur;
            cout << "  Title    : "; cin >> t;
            cout << "  Director : "; cin >> a;
            cout << "  Due      : "; cin >> d;
            cout << "  Duration : "; cin >> dur;
            try   { dv->setDuration(dur); }
            catch (invalid_argument& e) { cout << "  Error: " << e.what() << "\n"; delete dv; continue; }
            dv->setTitle(t); dv->setAuthor(a); dv->setDueDate(d);
            library.addItem(dv);
        }
        else if (choice == 3)
        {
            Magazine* m = new Magazine();
            string t, a, d; int issue;
            cout << "  Title     : "; cin >> t;
            cout << "  Publisher : "; cin >> a;
            cout << "  Due       : "; cin >> d;
            cout << "  Issue No. : "; cin >> issue;
            try   { m->setIssue(issue); }
            catch (invalid_argument& e) { cout << "  Error: " << e.what() << "\n"; delete m; continue; }
            m->setTitle(t); m->setAuthor(a); m->setDueDate(d);
            library.addItem(m);
        }
        else if (choice == 4) { library.displayAll(); }
        else if (choice == 5) { int id; cout << "  Item index: "; cin >> id; library.checkOut(id); }
        else if (choice == 6) { int id; cout << "  Item index: "; cin >> id; library.returnItem(id); }
        

    } while (choice != 7);

    cout << "\n  Goodbye!\n";
    return 0;
}