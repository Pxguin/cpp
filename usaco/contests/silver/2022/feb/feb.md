# USACO Silver 2022 Feb

## 3. Email Filing
Despite being a pretty useful problem for real life, the implementation is pretty tedious to do.

Given the current window of emails and folders that we can see, we want to file as many emails as possible until we can't anymore. We have two options after this: because we can't scroll upwards in the folder list, then we will only scroll down if no more emails need to be filed into the topmost folder. This exposes a new folder, giving us more options.

The second option, if we're still stuck, is to scroll the email list down by $1$ and expose a new email. This may be unoptimal but it is the only valid move. Note that we can only do this a certain number of times. If we get to the end of the emails, then we can't scroll down anymore, so if we're stuck at that point then it's impossible to file all emails. Otherwise, we can see that it is possible to file all emails.

I maintain the current set of emails with a double linked list (with two pointers corresponding to the current window) to keep the runtime at $O(N+M)$ per test case, but a set also works. Implementation details are in my code; I made sure to leave a lot of comments for this problem. I group the emails in the current window by the folder that they have to go in, which allows me to file emails in bulk pretty quickly. It also means that I file emails by looking at the destination folder, so when scrolling the folder list down, then it's really easy to backtrack to find which emails belong in the new exposed folder.