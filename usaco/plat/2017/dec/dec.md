# USACO Platinum 2017 December

## 3. Greedy Gift Takers
If some cow can't reach the front of the queue, then all cows behind her also can't reach the front. So the cows that can't get a gift must form a suffix of the original array. This, in essence, means that at any point in time, there is always at least one cow ahead of the first cow in the suffix.

We can binary search on the length of this suffix; the goal is to find the longest possible suffix that works. A suffix works if at any point in time, the complementary prefix stays nonempty.

Let the length of the suffix be $C$. All cows in the prefix satisfying $c_i\ge{C}$ will stay in the prefix, and all cows satisfying $c_i<C$ will become part of the suffix, so we update $C$. If we repeat this process until it reaches an equilibrium, then this suffix length works if the prefix is nonempty, and fails if the prefix is empty.