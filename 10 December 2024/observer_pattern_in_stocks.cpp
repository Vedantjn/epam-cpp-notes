#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Observer {
public:
    virtual void notify(const string& stock, double price) = 0; // Notify observers about stock price change
    virtual ~Observer() = default; // Virtual destructor
};

class StockExchange {
    unordered_map<string, double> stocks; // Map of stock names to prices
    vector<Observer*> observers;         // List of observers

public:
    void addStock(const string& stock, double price) {
        stocks[stock] = price;
    }

    void updateStock(const string& stock, double newPrice) {
        if (stocks.find(stock) != stocks.end()) {
            stocks[stock] = newPrice;
            notifyObservers(stock, newPrice); // Notify observers of the price change
        } else {
            cout << "Stock " << stock << " not found in exchange!" << endl;
        }
    }

    void registerObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void unregisterObserver(Observer* observer) {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

private:
    void notifyObservers(const string& stock, double price) {
        for (Observer* observer : observers) {
            observer->notify(stock, price); // Notify each observer
        }
    }
};

class Broker : public Observer {
    string name;

public:
    Broker(const string& name) : name(name) {}

    void notify(const string& stock, double price) override {
        cout << "Broker " << name << " notified: " << stock << " price updated to $" << price << endl;
    }
};

class Investor : public Observer {
    string name;

public:
    Investor(const string& name) : name(name) {}

    void notify(const string& stock, double price) override {
        cout << "Investor " << name << " notified: " << stock << " price updated to $" << price << endl;
    }
};

int main() {
    StockExchange exchange;

    // Adding some stocks to the exchange
    exchange.addStock("AAPL", 150.0);  // Apple
    exchange.addStock("GOOGL", 2800.0); // Alphabet (Google)
    exchange.addStock("AMZN", 3500.0);  // Amazon

    // Creating observers
    Broker broker1("Broker1");
    Broker broker2("Broker2");
    Investor investor1("Investor1");

    // Registering observers to the stock exchange
    exchange.registerObserver(&broker1);
    exchange.registerObserver(&broker2);
    exchange.registerObserver(&investor1);

    // Updating stock prices
    cout << "\nUpdating stock prices:\n";
    exchange.updateStock("AAPL", 155.0);
    exchange.updateStock("GOOGL", 2900.0);

    // Unregistering an observer
    cout << "\nUnregistering Broker1 and updating stock prices again:\n";
    exchange.unregisterObserver(&broker1);
    exchange.updateStock("AMZN", 3600.0);

    return 0;
}


// Updating stock prices:
// Broker Broker1 notified: AAPL price updated to $155
// Broker Broker2 notified: AAPL price updated to $155
// Investor Investor1 notified: AAPL price updated to $155
// Broker Broker1 notified: GOOGL price updated to $2900
// Broker Broker2 notified: GOOGL price updated to $2900
// Investor Investor1 notified: GOOGL price updated to $2900

// Unregistering Broker1 and updating stock prices again:
// Broker Broker2 notified: AMZN price updated to $3600
// Investor Investor1 notified: AMZN price updated to $3600