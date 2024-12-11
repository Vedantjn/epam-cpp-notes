// The Facade Design Pattern is a structural design pattern that provides a simplified interface to a larger 
// body of code, such as a complex subsystem. It hides the complexities of the system and provides an interface 
// for the client to interact with.

// Home Theater System
// Suppose you have a home theater system with several components (e.g., DVD player, sound system, projector). 
// The Facade class provides a unified interface to interact with all these subsystems.

#include<iostream>
using namespace std;

class DVDPlayer {
public:
    void on() {
        cout << "DVD Player is on\n";
    }
    void off() {
        cout << "DVD Player is off\n";
    }
    void play() {
        cout << "DVD Player is playing\n";
    }
};

class SoundSystem {
public:
    void on() {
        cout << "Sound System is on\n";
    }
    void off() {
        cout << "Sound System is off\n";
    }
    void setVolume(int level) {
        cout << "Volume set to" << level << "\n";
    }
};

class Projector {
public:
    void on() {
        cout << "Projector is on\n";
    }
    void off() {
        cout << "Projector is off\n";
    }
    void setWidescreenmode() {
        cout << "Projector set to widescreen\n";
    }
};

// Facade class : Home theater facade
class HomeTheaterFacade {
private:
    DVDPlayer* dvdPlayer;
    SoundSystem* soundSystem;
    Projector* projector;

public: 
    HomeTheaterFacade(DVDPlayer* dvd, SoundSystem* sound, Projector* proj) : dvdPlayer(dvd), soundSystem(sound), projector(proj) {}

    void watchMovie() {
        cout << "Preparing to watch a movie...\n";
        dvdPlayer->on();
        soundSystem->on();
        soundSystem->setVolume(27);
        projector->on();
        projector->setWidescreenmode();
        dvdPlayer->play();
        cout << "Movie is now playing!\n";
    }

    void endMovie() {
        cout << "Shutting down the home theater...\n";
        dvdPlayer->off();
        soundSystem->off();
        projector->off();
        cout << "Home theater shut down!\n";
    }
};

int main(){
    DVDPlayer dvd;
    SoundSystem sound;
    Projector projector;

    HomeTheaterFacade homeTheater(&dvd, &sound, &projector);

    homeTheater.watchMovie();
    cout << endl;
    homeTheater.endMovie();
    
    return 0;
}

// Preparing to watch a movie...
// DVD Player is on
// Sound System is on
// Volume set to27
// Projector is on
// Projector set to widescreen
// DVD Player is playing
// Movie is now playing!

// Shutting down the home theater...
// DVD Player is off
// Sound System is off
// Projector is off
// Home theater shut down!


// -------------------------------------------

// Subsystem Classes:

// DVDPlayer, SoundSystem, and Projector are the individual components of the home theater system. Each class provides methods to perform specific actions.
// Facade Class:

// The HomeTheaterFacade class acts as a unifying interface. It abstracts the complexities of interacting with the individual subsystems.
// Client:

// The client (main) interacts only with the HomeTheaterFacade. It does not need to know the details of how the subsystems work together.