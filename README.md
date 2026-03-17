*This project has been created as part of the 42 curriculum by oharoon.*

# Philosophers

## Description
`philo` is the mandatory 42 Philosophers project: a concurrency simulation of the dining philosophers problem using threads and mutexes.

The program receives:
- `number_of_philosophers`
- `time_to_die`
- `time_to_eat`
- `time_to_sleep`
- `[number_of_times_each_philosopher_must_eat]` (optional)

Each philosopher alternates between eating, sleeping, and thinking while competing for shared forks. The simulation stops when:
- one philosopher dies, or
- (if provided) all philosophers ate at least `number_of_times_each_philosopher_must_eat` times.

## Files
- `main.c`: entry point, one-philosopher special case, shutdown.
- `init.c`: parsing values into `t_data`, allocations, mutex and fork setup.
- `threads.c`: routine loop, per-philosopher supervisor, global meal monitor, thread creation/join.
- `actions.c`: logging and core actions (take/drop forks, eat, sleep).
- `extras.c`: time utilities, argument validation, `ft_atoi`.
- `extra_2.c`: cleanup and small helper functions.
- `philo.h`: structures, constants, function prototypes.
- `Makefile`: build rules.

## Instructions
### Build
From the project root:

```bash
make
```

### Run
Examples:

```bash
./philo 1 800 200 200
./philo 5 800 200 200
./philo 5 800 200 200 7
```

### Clean

```bash
make clean
make fclean
make re
```

## Implementation Overview
### Thread model
- One thread per philosopher (`routine`).
- One extra monitor thread (only when meal target is provided) checks completion condition.
- One supervisor thread per philosopher checks starvation timing.

### Fork model
- One mutex per fork.
- Each philosopher stores pointers to left and right fork mutexes.
- Eating requires locking both forks before printing `is eating`.

### Timing and death checks
- Timestamps are generated with `gettimeofday` in milliseconds.
- Each philosopher tracks `time_to_die` as an absolute deadline.
- Supervisor compares `get_time()` against that deadline and emits `died` once.

### Logging and synchronization
- Output lines are protected by the global `write` mutex so messages do not overlap.
- Philosopher-local state (`eating`, `eat_cont`, `time_to_die`) is guarded by each philosopher mutex.
- Shared counters (`dead`, `finished`) are coordinated by data-level mutex usage in monitor/supervisor paths.

## Recent Cleanup Applied
- Removed a leftover debug print in `threads.c` monitor.
- Fixed monitor-thread lifecycle to avoid detaching an uninitialized thread when meal target is not set.
- Corrected function prototype typo in `philo.h` (`supervisor`).
- Removed duplicate `routine` prototype in `philo.h`.
- Tightened argument validation to reject non-numeric tokens (e.g. `xx`, `12a`).
- Updated invalid argument output to subject-style `Error\n` on `stderr`.

## Subject Notes
Aligned with `en.subject.pdf` (Version 13.0):
- Mandatory program: `philo`.
- Mandatory APIs include pthread/mutex functions, `usleep`, `gettimeofday`, `printf`, etc.
- Global variables are forbidden.
- Log messages format follows subject states:
  - `has taken a fork`
  - `is eating`
  - `is sleeping`
  - `is thinking`
  - `died`

## Resources
- 42 subject: `en.subject.pdf`
- `man 3 pthread_create`
- `man 3 pthread_mutex_lock`
- `man 2 gettimeofday`
- `man 3 usleep`
- Dining philosophers background: synchronization and deadlock literature

AI usage for this repository:
- AI was used to help clean up small code issues and draft this `README.md`.
- All changes were validated by rebuilding and running sample executions locally.
