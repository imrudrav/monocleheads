//: Playground - noun: a place where people can play

//creating functions
func createMessage(someNumber: Int) -> String {
    print("You passed in the number: \(someNumber)")
    let message = " I LOVE YOU "
    print(message)
    return message
}

let result = createMessage(someNumber: 99)

//defining a class 
class Appliance {
    //properties
    var manufacturer: String = ""
    var model: String = ""
    var voltage: Int = 0
    var capacity: Int?
    
    //initializer
    init() {
        self.manufacturer = "default manufacturer"
        self.model = "default model"
        self.voltage = 220
        
    }
    //methods
    func getDetails() -> String {
        var message = "This is the \(self.model) from \(self.manufacturer)>"
        if self.voltage >= 220 {
            message += "This model is for European usage."
        }
        return message
    }
    
}


var kettle = Appliance()

print(kettle.manufacturer)

