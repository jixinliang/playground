use std::hint::black_box;
use std::sync::atomic::{AtomicU64, Ordering::Relaxed};
use std::thread;
use std::time::Instant;

// 该结构体必须是64字节对齐的
#[repr(align(64))]
struct Aligned(AtomicU64);

static A: [Aligned; 3] = [
    Aligned(AtomicU64::new(0)),
    Aligned(AtomicU64::new(0)),
    Aligned(AtomicU64::new(0)),
];

fn main() {
    black_box(&A);

    thread::spawn(|| loop {
        A[0].0.store(0, Relaxed);
        A[2].0.store(0, Relaxed);
    });

    let start = Instant::now();

    for _ in 0..100_000_000 {
        black_box(A[1].0.load(Relaxed));
    }

    println!("{:?}", start.elapsed());
}
