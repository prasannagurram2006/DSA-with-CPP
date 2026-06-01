IMPORTANT RULE

Kadane works when problem asks:

“best possible running value”

like:

maximum sum
maximum variance
best score

Kadane DOES NOT work well when problem asks:

exact sum
count of sums
fixed target k
longest subarray with sum k

because those require remembering previous sums.

Quick Summary
Problem	Kadane?
Maximum subarray sum	✅ Yes
Count subarrays with sum k	❌ No
Longest subarray with sum k	❌ No
Exact subarray sum k exists	❌ No
Maximum variance	✅ Modified Kadane
Maximum product subarray	✅ Modified Kadane
Core Intuition

Kadane says:

“Forget bad prefixes.”

But sum=k problems say:

“Old prefixes may become useful later.”

That is why Kadane usually fails for exact-k problems.