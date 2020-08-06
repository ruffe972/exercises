use ershov_island

create table craft (
	id_craft int not null primary key identity,
	name_craft nvarchar(20) not null unique,
	description nvarchar(200)
)

create table house (
	id_house int not null primary key identity,
	address nvarchar(50) not null unique,
	date_p date not null,
	date_s date,
	area float not null
)

create table person (
	id_person int not null primary key identity,
	surname nvarchar(20) not null,
	name nvarchar(15) not null,
	sex bit default 1 not null,
	date_r date not null,
	date_d date,
	father nvarchar(20),
	mother nvarchar(20),
)

create table occupant (
	id_person int not null foreign key references person(id_person),
	id_house int not null foreign key references house(id_house),
	date_n_p date not null,
	date_k_p date
)

create table businessman (
	id_person int not null foreign key references person(id_person),
	id_craft int not null foreign key references craft(id_craft),
	date_n_d date not null,
	date_k_d date,
	reason nvarchar(80),
	workmen int default 0 not null
)