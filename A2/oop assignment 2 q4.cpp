#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Post {
private:
    static int postCount;
    int postId;
    string content;
    int likes;
    int comments;

public:
    Post(string _content) : content(_content), likes(0), comments(0) {
        postId = ++postCount;
    }

    void display() const {
        cout << "Post ID: " << postId << endl;
        cout << "Content: " << content << endl;
        cout << "Likes: " << likes << endl;
        cout << "Comments: " << comments << endl;
    }

    void addComment() {
        ++comments;
    }

    void likePost() {
        ++likes;
    }
};

int Post::postCount = 0;

class User {
protected:
    string username;
    string email;
    string password;

public:
    User(string user, string e, string pass) : username(user), email(e), password(pass) {}

    virtual ~User() {}

    virtual void interactWithPost(Post& post) const = 0;
};

class RegularUser : public User {
private:
    static const int MAX_FEED_SIZE = 10;
    vector<Post*> feed;

public:
    RegularUser(string user, string e, string pass) : User(user, e, pass) {}

    void interactWithPost(Post& post) const override {
        post.likePost();
        cout << "Regular user liked the post!" << endl;
    }

    void addToFeed(Post* post) {
        if (feed.size() < MAX_FEED_SIZE) {
            feed.push_back(post);
        } else {
            cout << "Feed is full, cannot add more posts!" << endl;
        }
    }

    void viewFeed() const {
        cout << "Regular User Feed:" << endl;
        for (const auto& post : feed) {
            post->display();
        }
    }
};

class BusinessUser : public User {
private:
    static const int MAX_PROMOTED_POSTS = 10;
    int promotedPostsCount;

public:
    BusinessUser(string user, string e, string pass) : User(user, e, pass), promotedPostsCount(0) {}

    void interactWithPost(Post& post) const override {
        post.likePost();
        cout << "Business user liked the post!" << endl;
    }

    void promotePost(Post& post) {
        if (promotedPostsCount < MAX_PROMOTED_POSTS) {
            post.likePost();
            post.likePost();
            post.addComment(); 
            post.addComment(); 
            post.addComment(); 
            ++promotedPostsCount;
            cout << "Post promoted successfully!" << endl;
        } else {
            cout << "Cannot promote more posts, reached the limit!" << endl;
        }
    }
};

int main() {
    Post post1("This is post 1 content.");
    Post post2("This is post 2 content.");

    RegularUser regularUser("hamza", "hamza@gmail.com", "Fast1234");
    BusinessUser businessUser("murtaza", "murtaza@gmail.com", "Fast123");

    regularUser.addToFeed(&post1);
    regularUser.addToFeed(&post2);

    regularUser.viewFeed();

    businessUser.promotePost(post1);

    return 0;
}

