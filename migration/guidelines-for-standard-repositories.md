# Guidelines for standard repositories on GitHub

## Repository

* Give the repository a short, URL friendly, lowercase name: `dwc`
* Give the repository a longer, human friendly title: `Darwin Core`
* Initalize the repository with a `README.md`
* Enable the issue tracker (default)
* Deactivate the Wiki until used
* Add the standard website next to the description if available: http://rs.tdwg.org/dwc/

## README

* Write the README in Markdown
* Start with the title of the standard
* Add an abstract
* Indicate the permanent URL of the standard: http://www.tdwg.org/standards/450
* Include a preferred citation for the standard (as blockquote), including the name, authors and permanent URL

## Preferred citation

> Last name First name`,` Last name First name`.` year`.` Full name of the standard`, Version ` version number or date`. Biodiversity Information Standards (TDWG)` http://www.tdwg.org/standards/id (no trailing slash)

New versions can have more authors. Examples:

> Wieczorek John, Döring Markus, De Giovanni Renato, Robertson Tim, Vieglais Dave, Desmet Peter. 2014. Darwin Core, Version 2014-11-08. Biodiversity Information Standards (TDWG) http://www.tdwg.org/standards/450

> Access to Biological Collections Data task group. 2007. Access to Biological Collection Data (ABCD), Version 2.06. Biodiversity Information Standards (TDWG) http://www.tdwg.org/standards/115

## Management

* Create a [team to manage the standard](https://github.com/orgs/tdwg/teams)
* Give the team the same name as the repo (if possible), but mixed or uppercase: `DwC` This name serves both as a human friendly team title and URL friendly @mention (to notify a team): `@dwc` 
* Add a description for the team: `Darwin Core contributors`
* Invite at least one person to the team.

## Content

* Add old content to repo
* Archive old content as a [release](https://github.com/tdwg/dwc/releases)
* Update or replace old content with newer information/files

## Permanent URLs

* Permanent URLs are maintained by TDWG
* Permanent URL is of the form `http://www.tdwg.org/standards/id`: http://www.tdwg.org/standards/450/
* Permanent URL should redirect to GitHub repository: https://github.com/tdwg/dwc
* Permanent URL should be mentioned clearly in the README
* Permanent URL should be mentioned in the preferred citation
