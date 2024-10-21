# ConfiguratorWindow

In this project I used OOP principles to create a hierarchy of classes. CustomInputBar class is a base class for all other input bars. Pin object contains all types of these CustomInputBar objects, creating composition relationship between them. Configurations class aggregates pins, creating array of pins. And finally main window aggregates Configurations and Symbol objects, which represent left and right parts of the main window. 
Qt's signals and slots mechanism is used to implement some of pin and Configurations window functionality.
PinManager class is created to handle saving and loading states from and to Json files.
Symbol part will be implemented to represent each pin's visual representation according to it's current state, which will dynamically change after every modification to any of the pin's. For this functionality Chain of responsability design pattern will be used, to pass state change handling up into the object hierarchy.
