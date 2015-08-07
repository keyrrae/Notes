The rails new command created a new Rails app named MySite.

`$ rails new MySite`

The bundle install command installed all the software packages needed by the new Rails app.

These software packages are called gems and they are listed in the file **Gemfile**.

`$ bundle install`

The rails server command started the Rails development server, **WEBrick**

`$ rails server`

 `http://localhost:8000`

 request/response cycle

`$ rails generate controller Pages`

open `app/controllers/pages_controller.rb`

Within the class PagesController, add a method home

```ruby
class PagesController < ApplicationController

  def home
  end

end
```

`app/views/pages/home.html.erb`
```html
<div class="main">
  <div class="container">
    <h1>Hello my name is __</h1>
    <p>I make Rails apps.</p>
  </div>
</div>
```

1.Whenn you type http://localhost:8000/welcome, the browser makes a request for the URL /welcome.

2.The request hits the Rails router.

3.The router maps the URL to a controller action to handle the request.

4.The controller action receives the request, and asks the model to fetch data from the database.


