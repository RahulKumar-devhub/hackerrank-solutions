// ──────────────────────────────────────────────────
// Link        https://www.hackerrank.com/challenges/virtual-functions/problem?isFullScreen=true
// Problem     Virtual Functions
// Difficulty  Medium
// Subdomain   Classes
// Platform    HackerRank
// Language    cpp
// Status      Accepted
// Submitted   2026-08-14, 08:57 p.m.
// ──────────────────────────────────────────────────


class Person {
protected:
    string name;
    int age;

public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;

    virtual ~Person() {}
};

class Professor : public Person {
private:
    int publications;
    int cur_id;

    static int id;

public:
    Professor() {
        cur_id = ++id;
    }

    void getdata() {
        cin >> name >> age >> publications;
    }

    void putdata() {
        cout << name << " " << age << " "
             << publications << " " << cur_id << endl;
    }
};

int Professor::id = 0;

class Student : public Person {
private:
    int marks[6];
    int cur_id;

    static int id;

public:
    Student() {
        cur_id = ++id;
    }

    void getdata() {
        cin >> name >> age;
        for(int i = 0; i < 6; i++) {
            cin >> marks[i];
        }
    }

    void putdata() {
        int sum = 0;

        for(int i = 0; i < 6; i++) {
            sum += marks[i];
        }

        cout << name << " " << age << " "
             << sum << " " << cur_id << endl;
    }
};

int Student::id = 0;
