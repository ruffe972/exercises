use ershov

create table book_user_record(
	id int identity primary key not null,
	book_id int foreign key references book(id) not null,
	site_user_id int foreign key references site_user(id) not null,
	rating int not null,
	book_status nvarchar(255) not null,
	comment nvarchar(511) not null
)