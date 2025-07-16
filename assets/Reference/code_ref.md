
***Tất cả dưới đây là do chatGPT làm mẫu thôi, sẽ có khác biệt với bài làm, vẫn phải tuân theo các quy định của bài làm***

# Code cho phần repository
```
class TextEmployeeRepository : public IEmployeeRepository {
private:
    vector<Employee*> _employees
    std::string _filename;
public:
    TextEmployeeRepository(const std::string& file) : filename(file) {}

    std::vector<Employee> loadAll() override {
        std::ifstream in(filename);
        _employees.clear();
        std::vector<const Employee*> list;
        Employee* e;
        while (in >> e.id >> e.name >> e.deptId /* >> ... */) {
            list.push_back((const Employee*)e);
            _employees.push_back(e);
        }
        
    }

    void saveAll(const std::vector<Employee>& employees) override {
        std::ofstream out(filename, std::ios::trunc);
        for (auto& e : employees) {
            out << e.id << " " << e.name << " " << e.deptId << "\n";
        }
    }

    void add(const Employee& e) override {
        auto list = loadAll();
        list.push_back(e);
        saveAll(list);
    }

    void remove(int employeeId) override {
        auto list = loadAll();
        list.erase(std::remove_if(list.begin(), list.end(),
                   [&](auto& x){ return x.id == employeeId; }),
                   list.end());
        saveAll(list);
    }

    void update(const Employee& e) override {
        auto list = loadAll();
        for (auto& x : list) if (x.id == e.id) x = e;
        saveAll(list);
    }
};
```

# Code cho phần Manager
```
class EmployeeManager {
private:
    IEmployeeRepository* repo;
public:
    EmployeeManager(IEmployeeRepository& r) : repo(r) {

    }

    void hire(const Employee& e) {
        repo.add(e);
    }

    void fire(int employeeId) {
        repo.remove(employeeId);
    }

    void updateInfo(const Employee& e) {
        repo.update(e);
    }

    const std::vector<Employee>& listAll() const { return repo->loadAll(); }
};

```