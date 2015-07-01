#Thread and Lock
	
	public class HelloWorld {
		public static void main(String[] args) throws InterruptedException {
			Thread myThread = new Thread() {
				public void run() {
					System.out.println("Hello from new thread");
				}
			};
			myThread.start();
			Thread.yield();
			System.out.println("Hello from main thread");
			myThread.join();
		}
	}


Thread.yield():
A hint to the scheduler that the current thread is willing to yield its current use of a
processor.

Race condition
behavior that depends on the relative timing of operations


	class Counter {
		private int count = 0;
		public synchronized void increment() { ++count;}
		public int getCount() {return count;}
	}
