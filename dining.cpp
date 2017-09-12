#include <iostream>
#include <thread>
#include <mutex>

std::mutex out;

void philosopher(int n, std::mutex *low, std::mutex *high)
{
  while (true)
    {
      out.lock();
      std::cout << "Philosopher " << n << " is thinking." << std::endl;
      out.unlock();

      low->lock();
      out.lock();
      std::cout << "Philosopher " << n << " picked up her low fork." << std::endl;
      out.unlock();

      high->lock();
      out.lock();
      std::cout << "Philosopher " << n << " picked up her high fork." << std::endl;
      out.unlock();

      out.lock();
      std::cout << "Philosopher " << n << " is eating." << std::endl;
      out.unlock();

      out.lock();
      std::cout << "Philosopher " << n << " is putting down her high fork." << std::endl;
      out.unlock();
      high->unlock();

      out.lock();
      std::cout << "Philosopher " << n << " is putting down her low fork." << std::endl;
      out.unlock();
      low->unlock();
    }
}

void usage(char *program)
{
  std::cout << "Usage: " << program << " N  (where 2<=N<=10)" << std::endl;
  exit(1);
}

int main(int argc, char *argv[])
{
  if (argc != 2)
    {
      usage(argv[0]);
    }

  // philosophers = argv[1]
  int philosophers;
  try
    {
      philosophers = std::stoi(argv[1]);
    }
  catch (std::exception)
    {
      usage(argv[0]);
    }
  if (philosophers < 2 || philosophers > 10)
    {
      usage(argv[0]);
    }

  // forks
  std::mutex *forks = new std::mutex[philosophers];

  // philosophers
  std::thread *ph = new std::thread[philosophers];
  for (int i=0; i<philosophers; ++i)
    {
      // make all philosophers pick up their "lowest fork first"
      int low = (i == (philosophers - 1) ? 0 : i);
      int high = (i == (philosophers - 1) ? i : i+1);
      ph[i] = std::thread(philosopher, i, &forks[low], &forks[high]);
    }

  ph[0].join();
  delete[] forks;
  delete[] ph;

  return 0;
}
