#include<iostream>
#include<omp.h>
using namespace std;
int main()
{
	int a1[100][100],  result[100][100];

	double init_time,final_time;
	int size = 100;
    init_time=omp_get_wtime();
	cout<<"Execution Time at init_time for default scheduling: "<<init_time<<endl;
	omp_set_num_threads(size);
#pragma omp parallel for	
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++) 
		{
			a1[i][j] = rand() % 50;		
		}		
	}

#pragma omp parallel for 
	
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++) 
		{
			for(int k=0;k<size;k++)
			{
				result[i][j] +=a1[i][k] * a1[k][j];

			}
		}
	}
	
    final_time = omp_get_wtime(); 
	cout<<"Time final_time for Default Scheduling: "<<final_time<<endl;
    cout<<"Difference in execution time: "<<final_time-init_time<<endl;

    init_time=omp_get_wtime();
	cout<<"Execution Time at init_time for dynamic scheduling "<<init_time<<endl;
	
#pragma omp parallel for	
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++) 
		{
			a1[i][j] = rand() % 50;		
		}
		
	}

#pragma omp parallel for schedule(dynamic) 
	
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++) 
		{
			for(int k=0;k<size;k++)
			{
				result[i][j] +=a1[i][k] * a1[k][j];

			}
		}

	}
	
	final_time = omp_get_wtime(); 
	cout<<"Time final_time for Dynamic Scheduling: "<<final_time<<endl;
    cout<<"Difference in execution time: "<<final_time-init_time<<endl;

    init_time=omp_get_wtime();
	cout<<"Execution Time at init_time for Static Scheduling "<<init_time<<endl;

	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++)
		{
			a1[i][j] = rand()%50;
		}
	}


#pragma omp parallel for schedule (static) 
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++) 
		{
			for(int k=0;k<size;k++)
			{
				result[i][j] +=a1[i][k] * a1[k][j];
			}
		}
	}
	final_time = omp_get_wtime(); 
	cout<<"\nTime final_time for Static Scheduling:\n"<<final_time<<endl;
    cout<<"Difference in execution time:"<<final_time-init_time<<endl;
	return 0;
}