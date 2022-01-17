--
-- PostgreSQL database dump
--

-- Dumped from database version 13.3 (Debian 13.3-1.pgdg100+1)
-- Dumped by pg_dump version 13.3 (Debian 13.3-1.pgdg100+1)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: app; Type: DATABASE; Schema: -; Owner: sanchezcarlosjr
--

CREATE DATABASE app WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE = 'en_US.utf8';


ALTER DATABASE app OWNER TO sanchezcarlosjr;

\connect app

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: add_event(text, timestamp without time zone, timestamp without time zone, text, character varying, character); Type: FUNCTION; Schema: public; Owner: sanchezcarlosjr
--

CREATE FUNCTION public.add_event(title text, starts timestamp without time zone, ends timestamp without time zone, venue text, postal character varying, country character) RETURNS boolean
    LANGUAGE plpgsql
    AS $$
DECLARE
 did_insert boolean := false;
 found_count integer;
 the_venue_id integer;
BEGIN
 SELECT venue_id INTO the_venue_id 
 FROM venues v
 WHERE v.postal_code=postal AND v.country_code=country 
 AND v.name ILIKE venue
 LIMIT 1;
 
 IF the_venue_id IS NULL THEN
 	INSERT INTO venues(name,postal_code,country_code)
	VALUES(venue, postal,country)
	RETURNING venue_id INTO the_venue_id;
	did_insert := true;
 END IF;
 
 RAISE NOTICE 'Venue found %', the_venue_id;
 
 INSERT INTO events(title, starts, ends, venue_id)
 VALUES (title, starts, ends, the_venue_id);
 RETURN did_insert;
 END;
 $$;


ALTER FUNCTION public.add_event(title text, starts timestamp without time zone, ends timestamp without time zone, venue text, postal character varying, country character) OWNER TO sanchezcarlosjr;

--
-- Name: all_of_my_tables; Type: VIEW; Schema: public; Owner: sanchezcarlosjr
--

CREATE VIEW public.all_of_my_tables AS
 SELECT pg_class.relname,
    pg_class.relkind
   FROM (pg_class
     JOIN pg_namespace ON ((pg_namespace.oid = pg_class.relnamespace)))
  WHERE ((pg_namespace.nspname = 'public'::name) AND (pg_class.relkind = 'r'::"char"));


ALTER TABLE public.all_of_my_tables OWNER TO sanchezcarlosjr;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: cities; Type: TABLE; Schema: public; Owner: sanchezcarlosjr
--

CREATE TABLE public.cities (
    name text NOT NULL,
    postal_code character varying(9) NOT NULL,
    country_code character(2) NOT NULL,
    CONSTRAINT cities_postal_code_check CHECK (((postal_code)::text <> ''::text))
);


ALTER TABLE public.cities OWNER TO sanchezcarlosjr;

--
-- Name: countries; Type: TABLE; Schema: public; Owner: sanchezcarlosjr
--

CREATE TABLE public.countries (
    country_code character(2) NOT NULL,
    country_name character varying(30)
);


ALTER TABLE public.countries OWNER TO sanchezcarlosjr;

--
-- Name: cities_with_country; Type: VIEW; Schema: public; Owner: sanchezcarlosjr
--

CREATE VIEW public.cities_with_country AS
 SELECT cities.name,
    cities.postal_code,
    cities.country_code,
    countries.country_name
   FROM (public.cities
     JOIN public.countries ON ((cities.country_code = countries.country_code)));


ALTER TABLE public.cities_with_country OWNER TO sanchezcarlosjr;

--
-- Name: events; Type: TABLE; Schema: public; Owner: sanchezcarlosjr
--

CREATE TABLE public.events (
    event_id integer NOT NULL,
    title text NOT NULL,
    starts timestamp without time zone DEFAULT (now())::timestamp without time zone NOT NULL,
    ends timestamp without time zone NOT NULL,
    venue_id integer,
    CONSTRAINT events_check CHECK ((ends > starts)),
    CONSTRAINT events_title_check CHECK ((title <> ''::text))
);


ALTER TABLE public.events OWNER TO sanchezcarlosjr;

--
-- Name: venues; Type: TABLE; Schema: public; Owner: sanchezcarlosjr
--

CREATE TABLE public.venues (
    venue_id integer NOT NULL,
    name character varying(255),
    street_address text,
    type character(7) DEFAULT 'public'::bpchar,
    postal_code character varying(9),
    country_code character(2),
    active boolean DEFAULT true NOT NULL,
    CONSTRAINT venues_type_check CHECK ((type = ANY (ARRAY['public'::bpchar, 'private'::bpchar])))
);


ALTER TABLE public.venues OWNER TO sanchezcarlosjr;

--
-- Name: events_by_country; Type: VIEW; Schema: public; Owner: sanchezcarlosjr
--

CREATE VIEW public.events_by_country AS
 SELECT events.title,
    countries.country_name
   FROM ((public.events
     JOIN public.venues ON ((venues.venue_id = events.venue_id)))
     JOIN public.countries ON ((countries.country_code = venues.country_code)));


ALTER TABLE public.events_by_country OWNER TO sanchezcarlosjr;

--
-- Name: events_event_id_seq; Type: SEQUENCE; Schema: public; Owner: sanchezcarlosjr
--

CREATE SEQUENCE public.events_event_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.events_event_id_seq OWNER TO sanchezcarlosjr;

--
-- Name: events_event_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: sanchezcarlosjr
--

ALTER SEQUENCE public.events_event_id_seq OWNED BY public.events.event_id;


--
-- Name: events_with_matched_venues; Type: VIEW; Schema: public; Owner: sanchezcarlosjr
--

CREATE VIEW public.events_with_matched_venues AS
 SELECT e.title,
    v.name
   FROM (public.events e
     JOIN public.venues v ON ((e.venue_id = v.venue_id)));


ALTER TABLE public.events_with_matched_venues OWNER TO sanchezcarlosjr;

--
-- Name: events_with_venues; Type: VIEW; Schema: public; Owner: sanchezcarlosjr
--

CREATE VIEW public.events_with_venues AS
 SELECT e.title,
    v.name
   FROM (public.events e
     LEFT JOIN public.venues v ON ((e.venue_id = v.venue_id)));


ALTER TABLE public.events_with_venues OWNER TO sanchezcarlosjr;

--
-- Name: the_venue_id; Type: TABLE; Schema: public; Owner: sanchezcarlosjr
--

CREATE TABLE public.the_venue_id (
    venue_id integer
);


ALTER TABLE public.the_venue_id OWNER TO sanchezcarlosjr;

--
-- Name: venues_venue_id_seq; Type: SEQUENCE; Schema: public; Owner: sanchezcarlosjr
--

CREATE SEQUENCE public.venues_venue_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.venues_venue_id_seq OWNER TO sanchezcarlosjr;

--
-- Name: venues_venue_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: sanchezcarlosjr
--

ALTER SEQUENCE public.venues_venue_id_seq OWNED BY public.venues.venue_id;


--
-- Name: venues_with_cities; Type: VIEW; Schema: public; Owner: sanchezcarlosjr
--

CREATE VIEW public.venues_with_cities AS
 SELECT v.venue_id,
    v.name AS venue,
    c.name AS city
   FROM (public.venues v
     JOIN public.cities c ON ((((v.postal_code)::text = (c.postal_code)::text) AND (v.country_code = c.country_code))));


ALTER TABLE public.venues_with_cities OWNER TO sanchezcarlosjr;

--
-- Name: events event_id; Type: DEFAULT; Schema: public; Owner: sanchezcarlosjr
--

ALTER TABLE ONLY public.events ALTER COLUMN event_id SET DEFAULT nextval('public.events_event_id_seq'::regclass);


--
-- Name: venues venue_id; Type: DEFAULT; Schema: public; Owner: sanchezcarlosjr
--

ALTER TABLE ONLY public.venues ALTER COLUMN venue_id SET DEFAULT nextval('public.venues_venue_id_seq'::regclass);


--
-- Data for Name: cities; Type: TABLE DATA; Schema: public; Owner: sanchezcarlosjr
--

COPY public.cities (name, postal_code, country_code) FROM stdin;
Portland	97205	us
\.


--
-- Data for Name: countries; Type: TABLE DATA; Schema: public; Owner: sanchezcarlosjr
--

COPY public.countries (country_code, country_name) FROM stdin;
us	United States
mx	Mexico
au	Australia
gb	United Kingdom
de	Germany
\.


--
-- Data for Name: events; Type: TABLE DATA; Schema: public; Owner: sanchezcarlosjr
--

COPY public.events (event_id, title, starts, ends, venue_id) FROM stdin;
1	LARP Club	2012-02-15 17:30:00	2012-02-15 19:30:00	2
2	April Fools Day	2012-04-01 00:00:00	2012-04-01 23:59:00	\N
3	Cristmas Day	2012-12-25 00:00:00	2012-12-25 23:59:00	\N
\.


--
-- Data for Name: the_venue_id; Type: TABLE DATA; Schema: public; Owner: sanchezcarlosjr
--

COPY public.the_venue_id (venue_id) FROM stdin;
1
10
2
3
\.


--
-- Data for Name: venues; Type: TABLE DATA; Schema: public; Owner: sanchezcarlosjr
--

COPY public.venues (venue_id, name, street_address, type, postal_code, country_code, active) FROM stdin;
1	Crystal Ballroom	\N	public 	97205	us	t
10	Crystal Ballroom 2	\N	public 	97205	us	t
2	Crystal Ballroom 3	\N	public 	97205	us	t
3	Voodoo Donuts	\N	public 	97205	us	t
\.


--
-- Name: events_event_id_seq; Type: SEQUENCE SET; Schema: public; Owner: sanchezcarlosjr
--

SELECT pg_catalog.setval('public.events_event_id_seq', 6, true);


--
-- Name: venues_venue_id_seq; Type: SEQUENCE SET; Schema: public; Owner: sanchezcarlosjr
--

SELECT pg_catalog.setval('public.venues_venue_id_seq', 4, true);


--
-- Name: cities cities_pkey; Type: CONSTRAINT; Schema: public; Owner: sanchezcarlosjr
--

ALTER TABLE ONLY public.cities
    ADD CONSTRAINT cities_pkey PRIMARY KEY (country_code, postal_code);


--
-- Name: countries countries_country_name_key; Type: CONSTRAINT; Schema: public; Owner: sanchezcarlosjr
--

ALTER TABLE ONLY public.countries
    ADD CONSTRAINT countries_country_name_key UNIQUE (country_name);


--
-- Name: countries countries_pkey; Type: CONSTRAINT; Schema: public; Owner: sanchezcarlosjr
--

ALTER TABLE ONLY public.countries
    ADD CONSTRAINT countries_pkey PRIMARY KEY (country_code);


--
-- Name: events events_pkey; Type: CONSTRAINT; Schema: public; Owner: sanchezcarlosjr
--

ALTER TABLE ONLY public.events
    ADD CONSTRAINT events_pkey PRIMARY KEY (event_id);


--
-- Name: venues venues_pkey; Type: CONSTRAINT; Schema: public; Owner: sanchezcarlosjr
--

ALTER TABLE ONLY public.venues
    ADD CONSTRAINT venues_pkey PRIMARY KEY (venue_id);


--
-- Name: events_starts; Type: INDEX; Schema: public; Owner: sanchezcarlosjr
--

CREATE INDEX events_starts ON public.events USING btree (starts);


--
-- Name: cities cities_country_code_fkey; Type: FK CONSTRAINT; Schema: public; Owner: sanchezcarlosjr
--

ALTER TABLE ONLY public.cities
    ADD CONSTRAINT cities_country_code_fkey FOREIGN KEY (country_code) REFERENCES public.countries(country_code);


--
-- Name: events events_venue_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: sanchezcarlosjr
--

ALTER TABLE ONLY public.events
    ADD CONSTRAINT events_venue_id_fkey FOREIGN KEY (venue_id) REFERENCES public.venues(venue_id);


--
-- Name: venues venues_country_code_postal_code_fkey; Type: FK CONSTRAINT; Schema: public; Owner: sanchezcarlosjr
--

ALTER TABLE ONLY public.venues
    ADD CONSTRAINT venues_country_code_postal_code_fkey FOREIGN KEY (country_code, postal_code) REFERENCES public.cities(country_code, postal_code) MATCH FULL;


--
-- PostgreSQL database dump complete
--

