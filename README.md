# Cinux

Linus Torvalds has been sold out to big tech companies like Google and Microsoft. He himself is a billionaire and no longer writes any code. Many people, including myself, are very unhappy with his decisions, like the removal of several Russian developers from kernel maintainership status. See [Several Russian developers lose kernel maintainership status](https://lwn.net/Articles/995186/ ).

This problematic decision is not an isolated incident. Recent dramas include adding Rust language developers like Alex Gaynor, who literally does nothing. See [Unsafe Hell! Code review of "Rust for Linux" github project](https://youtu.be/5FOtPZVEddU?si=RqFzw-yDmC0Fp2Vn). His hatred towards C++ is another issue. It is no wonder nobody wants to contribute to Linux anymore. He really should not complain. There are also many other fundamental disagreements between me and him, such as no crashing for out-of-bounds errors, allocation failure, etc. I always support fail-fast for abstraction machine corruption and programming bugs.


See:
https://www.youtube.com/watch?v=5FOtPZVEddU

Also his hatred towards C++ which is another thing. No wonder nobody wants to contribute Linux any more. He really should not complain.

Also many other fundamental disagreement between me and himself, like no crashing for out of bounds, allocation failure etc.

## What is my plan?

Maybe it is time to start a fork and rename it to Cinux (cqwrteur's Linux). I would like to first fix the kernel headers issues that break the UAPI for C++ compilers (because they use C++ keywords that break C++ code) and the Windows filesystem (Windows filesystem is case-insensitive, so some headers cannot be stored on Windows filesystems).

If I can, I will start to fix the kernel headers to support using freestanding C++ (needs C++26 standard at least, otherwise it would be too broken) in the kernel with this portable C++ guideline. We will not use C++ exceptions or RTTI, but will wait for P0709 [Herbceptions Proposal](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2019/p0709r4.pdf). For a lot of functionalities missing in the C++ standard library (like array, vector) for freestanding, my fast_io library should be a fine replacement. See here.

I will also try to first merge important forks like Asahi Linux for Apple Silicon support (the rust issue is another matter since Rust language developers and Rust foundations are very hostile to Russia and China). I will try to contain it before we have new solutions, for example, a rewrite. Important forks also include Linux on Microsoft Surface.