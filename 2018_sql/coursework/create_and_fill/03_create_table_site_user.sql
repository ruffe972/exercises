use ershov

create table site_user(
	id int identity primary key not null,
	username nvarchar(255) not null,
	pw_hash nvarchar(255) not null,
	male bit,
	bot bit not null
)