#Concurrency Models

##Parallelism and concurrency

A concurrent program has multiple logical threads of control. These threads may or may not run in parallel.

A parallel program potentially runs more quickly than a sequential program by executing different parts of the computation simultaneously (in parallel). It may or may not have more than one logical thread of control.

Concurrency is about dealing with lots of things at once.
Parallelism is about doing lots of things at once.

This is unfortunate because concurrent programs are often nondeterministic —they will give different results depending on the precise timing of events. If you’re working on a genuinely concurrent problem, nondeterminism is natural and to be expected. Parallelism, by contrast, doesn’t necessarily imply nondeterminism—doubling every number in an array doesn’t (or at least, shouldn’t) become nondeterministic just because you double half the numbers on one core and half on another. Languages with explicit support for parallelism allow you to write parallel code without introducing the specter of nondeterminism.

Bit-Level Parallelism
Instruction-Level Parallelism
     pipelining, out-of-order execution, and speculative execution

Data Parallelism
“single instruction, multiple data”)
most amenable to data parallelism is image processing. To increase the brightness of an image, for example, we increase the brightness of each pixel. For this reason, modern GPUs (graphics processing units) have evolved into extremely powerful data-parallel processors.

Task-Level Parallelism
Concurrent Software for a Concurrent World
Distributed Software for a Distributed World
Resilient Software for an Unpredictable World

Simple Software in a Complex World
but a concurrent solution can be simpler and clearer than its sequential equivalent when written in the right language with the right tools. This is particularly true whenever you’re dealing with an intrinsically concurrent real-world problem.

##Thread and Lock
locking conditions apply only to data that is both shared between threads and might
change—in other words *shared mutable state*.

Data that doesn’t change (is
immutable) can be accessed by multiple threads without any kind of locking.
	
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


GitTest