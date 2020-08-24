use ershov_island;

go
create proc register_person @req_id_person int, @req_address varchar(50) as
	declare @area_per_person_limit float = 20;

	declare @req_id_house int;
	select @req_id_house = id_house from house
	where address = @req_address;

	declare @neighbors_count int;
	with neighbors as
		(select distinct id_person from occupant
		where id_house = @req_id_house)
	select @neighbors_count = count(*) from neighbors;

	declare @house_area float;
	select @house_area = area from house
	where id_house = @req_id_house;

	declare @area_per_person float = @house_area / (@neighbors_count + 1);

	if @area_per_person > @area_per_person_limit
		print 'Недостаточно жилой площади.';
	else
		insert into occupant values
		(@req_id_person, @req_id_house, getdate(), NULL);
go