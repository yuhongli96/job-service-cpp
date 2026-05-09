#include "functions.ih"

void submitJob(JobManager &jobManager)
{
    cout << "\n"
            "Enter file path: ";
    
    string filename; 
    cin >> ws;                          // remove all leading ws          
    getline(cin, filename);

    cout << "Job submitted successfully\n"
            "Job ID: " << jobManager.submit(filename) << '\n';
}