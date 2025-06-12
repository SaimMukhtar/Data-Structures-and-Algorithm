#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//```````````````````````````````````````````````````````````````````````````` Open HTML File ```````````````````````````````````````````````````````````````````````
void openHtmlFile(const string& url) {
    string filePath = url;  // Directly use the URL as file path
#ifdef _WIN32
    string command = "start " + filePath;
#elif __linux__
    string command = "xdg-open " + filePath;
#elif __APPLE__
    string command = "open " + filePath;
#else
    cerr << "Unsupported operating system" << endl;
    return;
#endif
    system(command.c_str());
}

//```````````````````````````````````````````````````````````````````````````` Browser History Class ```````````````````````````````````````````````````````````````
class BrowserHistory {
private:
    string history[100];           // Stores visited URLs
    int visitCount[100] = {0};     // Tracks visit counts for each URL
    int currentIndex;              // Current position in history
    int totalUrls;                 // Total number of unique URLs visited

public:
    //```````````````````````````````````````````````````````````````````````````` Constructor ```````````````````````````````````````````````````````
    BrowserHistory(const string& homepage) {
        currentIndex = 0;
        totalUrls = 1;
        history[0] = homepage;
        visitCount[0]++;
        openHtmlFile(homepage);
    }

    //```````````````````````````````````````````````````````````````````````````` Visit a New URL ```````````````````````````````````````````````````
    void visit(const string& url) {
        currentIndex++;
        history[currentIndex] = url;
        totalUrls = currentIndex + 1;
        visitCount[currentIndex]++;
        openHtmlFile(url);
    }

    //```````````````````````````````````````````````````````````````````````````` Back in History `````````````````````````````````````````````````
    string back(int steps) {
        if (steps > currentIndex) {
            currentIndex = 0;
        } else {
            currentIndex -= steps;
        }
        visitCount[currentIndex]++;
        openHtmlFile(history[currentIndex]);
        return history[currentIndex];
    }

    //```````````````````````````````````````````````````````````````````````````` Forward in History `````````````````````````````````````````````````
    string forward(int steps) {
        if (currentIndex + steps >= totalUrls) {
            currentIndex = totalUrls - 1;
        } else {
            currentIndex += steps;
        }
        visitCount[currentIndex]++;
        openHtmlFile(history[currentIndex]);
        return history[currentIndex];
    }

    //```````````````````````````````````````````````````````````````````````````` Open Top K Visited URLs ```````````````````````````````````````````
    void openTopKVisited(int k) {
        for (int i = 0; i < k && i < totalUrls; i++) {
            int maxIndex = 0;
            for (int j = 1; j < totalUrls; j++) {
                if (visitCount[j] > visitCount[maxIndex]) {
                    maxIndex = j;
                }
            }
            // Reset the visit count to avoid opening the same URL repeatedly
            visitCount[maxIndex] = -1;
            openHtmlFile(history[maxIndex]);
        }
    }

    //```````````````````````````````````````````````````````````````````````````` Get Current URL ```````````````````````````````````````````````````
    string getCurrentUrl() const {
        return history[currentIndex];
    }
};

//```````````````````````````````````````````````````````````````````````````` Main Function ```````````````````````````````````````````````````````
int main() {
    // Create browser history with initial homepage
    BrowserHistory browser("saim1.com.html");

    // Simulate browsing different URLs
    browser.visit("saim2.com.html");
    browser.visit("saim3.com.html");

    // Display current URL
    cout << "Current URL: " << browser.getCurrentUrl() << endl;

    // Go back in history by 1 step
    browser.back(1);
    cout << "After moving back, current URL: " << browser.getCurrentUrl() << endl;

    // Go forward in history by 1 step
    browser.forward(1);
    cout << "After moving forward, current URL: " << browser.getCurrentUrl() << endl;

    // Open top 2 most frequently visited URLs
    browser.openTopKVisited(2);

    return 0;
}
