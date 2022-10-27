create table null_table(id int, age int nullable, name char nullable, score float);
create unique index index_1 on null_table(age);
create unique index index_3 on null_table(id, name);

insert into null_table values(1, 1, 'a', 1.0);
insert into null_table values(2, 2, 'b', 2.0), (3, 3, 'c', 1.0), (4, 4, 'd', 4.0);


insert into null_table values(5, null, 'e', 5.0);

insert into null_table values(6, null, null, 6.0);  -- success

insert into null_table values(7, 7, null, 6.0);

insert into null_table values(7, 8, null, 8.0);     -- success

update null_table set score=(select null_table.score from null_table where null_table.id = 2) where id = 4;

update null_table set score=(select null_table.score from null_table where null_table.id = 2) where id = 8;

select * from null_table;



