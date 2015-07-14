### MVC Pattern
This software engineering pattern separates data(model), user interface(view),
and data handling logic(controller), so that one can be changed without
affecting the others.

Designers can work on the interface without worrying about data storage or management.

Developers are able to program the logic of data handling without getting into
the details of presentation.

Python was chosen over many other scripting languages for the following reasons:

Clean and elegant syntax.

Large standard library of modules that covers a wide range of tasks.

Extensive documentation.

Mature runtime environment.

Support for standard and proven technologies such as Linux and Apache.

Django

A template and text filtering engine with simple but extensible syntax.

A form generation and validation API.

An extensible authentication system.

A caching system for speeding up the performance of applications.

A feed framework for generating RSS feeds.

setting.py

```Python
# Django settings for django_bookmarks project.
DEBUG = True
TEMPLATE_DEBUG = DEBUG
ADMINS = (
  # ('Your Name', 'your_email@domain.com'),
)
MANAGERS = ADMINS
DATABASE_ENGINE = ''    # 'postgresql_psycopg2', 'postgresql',
                        # 'mysql', 'sqlite3' or 'ado_mssql'.
DATABASE_NAME = ''      # Or path to database file
                        # if using sqlite3.
DATABASE_USER = ''      # Not used with sqlite3.
DATABASE_PASSWORD = ''  # Not used with sqlite3.
DATABASE_HOST = ''      # Set to empty string for localhost.
                        # Not used with sqlite3.
DATABASE_PORT = ''      # Set to empty string for default.
                        # Not used with sqlite3.
# The rest of the file was trimmed.
```
