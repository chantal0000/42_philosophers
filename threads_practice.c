// MULTI-THREADED PROGRAM

// parallel execution
// cuncurrently | gleichzeitig | zeitgleich

// steps
// 1. pthread_create -> to create a thread
// 2. we give it a function to run
// 3. pthread_join back with main thread

// library for pthread
#include <pthread.h>
#include <stdio.h>

// Computation | Berechnung
void	*computation(void *num)
{
	int sum = 0;
	int i = 0;
	int *number = (int *) (num);

	while (i < 100000000)
	{
		sum += *number;
		i++;
	}

	// printf("result = %i\n", sum);
	return NULL;
}



int	main()
{
	// create a thread
	pthread_t	thread1;
	pthread_t	thread2;

	int			value1 = 1;
	int			value2 = 2;
	// creates a function and run it in a different thread
	// &thread1 -> pointer to our pthread var
	// NULL -> can be used to set attributes to the thread
	// computation -> which function
	// NULL -> can be used to send arguments to the function


	// pthread_create(&thread1, NULL, computation, (void*) &value1);
	// pthread_create(&thread2, NULL, computation, (void*) &value2);
	// // join thread back with the main thread when it is done
	// // NULL -> could be used to work with return value of the
	// pthread_join(thread1, NULL);
	// pthread_join(thread2, NULL);

	computation((void *) &value1);
	computation((void *) &value2);


	return (0);
}
