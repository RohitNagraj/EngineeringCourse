def atomicdictionary():
    atomic = {"H":"Hydrogen","He":"Helium","Li":"Lithium","Be":"Berrylium","B":"Boron","C":"Carbon","N":"Nitrogen","F":"Fluorine","Ne":"Neon"}
    print(atomic)
    sym = input("Enter an existing symbol: ")
    name = input("Enter an element name: ")
    atomic[sym] = name
    print(atomic)
    sym = input("Enter a new symbol: ")
    name = input("Enter a new element name: ")
    atomic[sym] = name
    print(atomic)
    print("No. of elements: ",len(atomic))
    ele=input("Enter element to search: ")
    for i in atomic:
        if(i==ele):
            print("Element found!")


