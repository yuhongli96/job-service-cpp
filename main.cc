#include "main.ih"

int main()
{
    JobManager jobManag;
    size_t choice;
    string line;

    while (true)
    {
        showMenu();

        cout << "\n"
                "Choose an option: ";

        getline(cin >> ws, line);       // remove any leading ws

        if (!isNumber(line))           // handle non-numeric input
        {
            cout << "Please enter a number.\n";
            continue;
        }

        choice = stoul(line);

        switch (choice)
        {
            case 1:
                submitJob(jobManag);
            break;

            case 2:
                showStatus(jobManag);
            break;

            case 3:
                showResult(jobManag);
            break;

            case 4:
                list(jobManag);
            break;

            case 5:
                jobManag.stop();
                return 0;
            break;

            default:
                cout << "The selected option is not available.\n";
            break;
        }
    }
    
}
