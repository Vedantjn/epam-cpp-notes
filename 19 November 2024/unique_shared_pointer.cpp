// Key Differences Between std::unique_ptr and std::shared_ptr:

// Feature             std::unique_ptr           std::shared_ptr
// --------            ----------------          ---------------
// Ownership           Exclusive                 Shared
// Copyable            No (only movable)         Yes (shared ownership)
// Reference Count     None                      Maintains reference count
// Overhead            Minimal                   Higher due to reference counting
// Use Case            Single-owner scenarios    Multiple-owner scenarios

// When to Use:
// -----------
// unique_ptr:
//     Use when you need exclusive ownership and no sharing is required 
//     (e.g., managing resources in a single thread).

// shared_ptr:
//     Use when multiple objects need to share ownership of a resource 
//     (e.g., managing shared resources across threads or objects).