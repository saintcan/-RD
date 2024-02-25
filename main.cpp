#include <iostream>
#include <vector>

// Абстрактний спостерігач
class Observer {
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

// Абстрактний суб'єкт (видавець)
class Subject {
protected:
    std::vector<Observer*> observers;

public:
    virtual void attach(Observer* observer) {
        observers.push_back(observer);
    }

    virtual void detach(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    virtual void notify(float temperature, float humidity, float pressure) {
        for (Observer* observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }
};

// Конкретний суб'єкт (конкретний видавець) - клас, що представляє погоду
class WeatherData : public Subject {
private:
    float temperature;
    float humidity;
    float pressure;

public:
    void setMeasurements(float temp, float hum, float pres) {
        temperature = temp;
        humidity = hum;
        pressure = pres;
        notify(temperature, humidity, pressure);
    }
};

// Конкретний спостерігач - відображення погоди на екрані
class Display : public Observer {
public:
    void update(float temperature, float humidity, float pressure) override {
        std::cout << "Current conditions: " << temperature << "C, " << humidity << "% humidity, " << pressure << "hPa pressure" << std::endl;
    }
};

int main() {
    WeatherData weatherData;

    Display display1;
    Display display2;

    weatherData.attach(&display1);
    weatherData.attach(&display2);

    weatherData.setMeasurements(25.0f, 60.0f, 1013.0f);

    weatherData.detach(&display1);

    weatherData.setMeasurements(27.0f, 55.0f, 1010.0f);

    return 0;
}
