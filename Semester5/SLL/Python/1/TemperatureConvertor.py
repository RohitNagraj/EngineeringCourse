def FarenToCelcius():
    temp = int(
        input("please enter the farenheit temprature to convert it into celcius: "))
    celcius = (temp-32)*(5/9)
    print("The corresponding celcius temprature is ", celcius)
    return


def FarenToKelvin():
    temp = int(
        input("please enter the farenheit temprature to convert it into kelvin:"))
    kelvin = (temp-32)*(5/9)+273
    print("The corresponding kelvin temprature is ", kelvin)
    return


def CelciusToKelvin():
    temp = int(
        input("please enter the celcius temprature to convert it into kelvin: "))
    kelvin = temp+273
    print("The corresponding celcius temprature is ", kelvin)
    return


def CelciusToFaren():
    temp = int(
        input("please enter the celcius temprature to convert it into Farenheit: "))
    faren = (9/5)*(temp)+32
    print("The corresponding celcius temprature is ", faren)
    return


def KelvinToFaren():
    temp = int(
        input("please enter the kelvin temprature to convert it into Farenheit: "))
    faren = (9/5)*(temp+273)+32
    print("The corresponding celcius temprature is ", faren)
    return


def KelvinToCelcius():
    temp = int(
        input("please enter the kelvin temprature to convert it into celcius: "))
    celcius = (temp-273)
    print("The corresponding celcius temprature is ", celcius)
    return


while True:
    print("Welcome to temprature conversion system ")
    print("MENU")
    print("1.Farenheit to celcius ")
    print("2.Farenheit to kelvin ")
    print("3.celcius to farenheit ")
    print("4.celcius to kelvin ")
    print("5.kelvin to farenheit ")
    print("6.kelvin to celcius ")
    print("7. Exit")
    choice = int(input("choose from the following options: "))
    if choice == 1:
        FarenToCelcius()
    elif choice == 2:
        FarenToKelvin()
    elif choice == 3:
        CelciusToKelvin()
    elif choice == 4:
        CelciusToFaren()
    elif choice == 5:
        KelvinToFaren()
    elif choice == 6:
        KelvinToCelcius()
    elif choice == 7:
        exit()
    else:
        print("Wrong choice!")
