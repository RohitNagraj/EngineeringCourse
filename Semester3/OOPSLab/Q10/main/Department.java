package main;

import main.Faculty;

public interface Department {
    void readData(Faculty f); // Faculty object is needed because this function is defined in
    // ISE_Department class and hence, it cannot be called on the faculty object
    // directly.

    void printData(Faculty f);

    // void printNumberDesignations(Faculty f); I chose to not include these as
    // their functionality wasn't defined

    // void numberResearchConsultancyProjs(Faculty f);
}
