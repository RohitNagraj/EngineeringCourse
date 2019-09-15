package main;

import main.Faculty;

public interface Department {
    void readData(Faculty f); // Faculty object is needed because this function will be defined in
    // ISE_Department class and hence, it cannot be call the faculty object
    // directly since its at a higher level package.

    void printData(Faculty f);

    // void printNumberDesignations(Faculty f); I chose to not include these as
    // their functionality wasn't defined

    // void numberResearchConsultancyProjs(Faculty f);
}
