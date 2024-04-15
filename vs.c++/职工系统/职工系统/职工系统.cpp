#include"workermanager.h"
int main()
{
	workermanager mn;
	mn.show_menu();
	int input;
	do 
	{
		cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ:>" << endl;
		cin >> input;
		switch (input) 
		{
		case 0: {
			mn.save();
			return 0;
		}
		case 1: {
			mn.add_worker();
			break;
		}
		case 2: {
			mn.look_workers();
			break;
		}
		case 3: {
			mn.del_workers();
			break;
		}
		case 4: {
			mn.mod_worker();
			break;
		}
		case 5: {
			mn.find_worker();
			break;
		}
		case 6: {
			mn.sort_worker();
			break;
		}
		case 7: {
			mn.clear_worker();
			break;
		}
		default:
			cout << "ÊäÈë´íÎó" << endl;
			break;
		}
	} while (input);
	return 0;
}